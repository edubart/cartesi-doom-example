CARTESI_MACHINE_LIB_DIR=/home/bart/projects/cartesi/corp/machine-emulator-sdk/emulator/src

NELUA_GEN_FLAGS=-Pnogc -Pnochecks -Pnoassertloc -Pnocwarnpragmas -Pnocstaticassert --release --no-cache
RISCV_CC=riscv64-cartesi-linux-gnu-gcc
RISCV_CFLAGS=-O2 -fwrapv -fno-strict-aliasing -flto=auto -DNDEBUG -Wno-incompatible-pointer-types
RISCV_LDFLAGS=-s -Wl,-O1,--sort-common,--build-id=none -z relro -z now
RISCV_NELUA_FLAGS=--cc=$(RISCV_CC) $(NELUA_GEN_FLAGS)

HOST_CC=emcc
HOST_CFLAGS=-fwrapv -fno-strict-aliasing -Wno-incompatible-pointer-types -Wno-parentheses-equality -Wno-unused-value -I./fbdoom-machine/deps
HOST_LIBS=-lcartesi
HOST_LDFLAGS=-L"$(CARTESI_MACHINE_LIB_DIR)" $(HOST_LIBS) -s TOTAL_MEMORY=512MB -sNO_DISABLE_EXCEPTION_CATCHING --preload-file images
HOST_NELUA_FLAGS=--cc=$(HOST_CC) $(NELUA_GEN_FLAGS)

.PHONY: machine rootfs download-rootfs all test clean distclean

machine: build/fbdoom-machine.html

gen-c: fbdoom-machine/fbdoom-machine.c rivlib/riv.c

rootfs: images/fbdoom_rootfs.ext2

download-rootfs:
	wget -O images/fbdoom_rootfs.ext2 https://github.com/edubart/cartesi-doom-example/releases/download/v0.0.1/fbdoom_rootfs.ext2

all: build/fbdoom-machine.html images/fbdoom_rootfs.ext2

test: build/fbdoom-machine.html
	./build/fbdoom-machine.html

build:
	mkdir -p build

build/fbdoom-machine.html: | build
	$(HOST_CC) $(HOST_CFLAGS) -o $@ fbdoom-machine/fbdoom-machine.c $(HOST_LDFLAGS)

build/libriv.so: | build
	$(RISCV_CC) $(RISCV_CFLAGS) -shared -fPIC -o $@ rivlib/riv.c $(RISCV_LDFLAGS)

fbdoom-machine/fbdoom-machine.c: fbdoom-machine/fbdoom-machine.nelua fbdoom-machine/deps/*.nelua fbdoom-machine/deps/*.h rivlib/riv.nelua | build
	nelua $(HOST_NELUA_FLAGS) --ldflags="-L$(CARTESI_MACHINE_LIB_DIR)" -o $@ $<

rivlib/riv.c: rivlib/riv.nelua rivlib/*.nelua rivlib/deps/*.nelua | build
	nelua $(RISCV_NELUA_FLAGS) -Pnoentrypoint -DRIV_IMPLEMENTATION=true -o $@ $<

build/fbdoom_rootfs.tar: Dockerfile build/libriv.so build/fbdoom
	docker buildx build --progress plain --output type=tar,dest=$@ .

build/fbdoom: build/libriv.so fbdoom/*.c fbdoom/*.h
	$(MAKE) -C fbdoom

images/fbdoom_rootfs.ext2: build/fbdoom_rootfs.tar scripts/pack-ext2.sh
	scripts/pack-ext2.sh $< $@

clean:
	rm -rf build

distclean: clean
	rm -f images/fbdoom_rootfs.ext2 rivlib/riv.c fbdoom-machine/fbdoom-machine.c
