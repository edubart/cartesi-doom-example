/* Generated by Nelua 0.2.0-dev */
/* Compile command: riscv64-cartesi-linux-gnu-gcc -x c "rivlib/riv.c" -x none -fwrapv -fno-strict-aliasing -O2 -DNDEBUG -o "rivlib/riv" */
/* Compile hash: 4BLZUFaVtbHSzRDdTZNReL1VPj8J */
/* ------------------------------ DIRECTIVES -------------------------------- */
/* Enable 64 bit offsets for stdio APIs. */
#if !defined(_FILE_OFFSET_BITS) && __SIZEOF_LONG__ >= 8
  #define _FILE_OFFSET_BITS 64
#endif
/* Enable POSIX APIs in included headers. */
#if !defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE) && !defined(_GNU_SOURCE) && !defined(_DEFAULT_SOURCE)
  #if defined(__gnu_linux__)
    #define _GNU_SOURCE
  #else
    #define _XOPEN_SOURCE 600
  #endif
#endif
#include <stdint.h>
/* Macro used to force inlining a function. */
#ifdef __GNUC__
  #define NELUA_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
  #define NELUA_INLINE __forceinline
#elif __STDC_VERSION__ >= 199901L
  #define NELUA_INLINE inline
#else
  #define NELUA_INLINE
#endif
#define NELUA_NIL (nlniltype){}
/* Macro used sign that a type punning cast may alias (related to strict aliasing). */
#ifdef __GNUC__
  #define NELUA_MAYALIAS __attribute__((may_alias))
#else
  #define NELUA_MAYALIAS
#endif
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <string.h>
/* Macro used for branch prediction. */
#if defined(__GNUC__) || defined(__clang__)
  #define NELUA_UNLIKELY(x) __builtin_expect(x, 0)
#else
  #define NELUA_UNLIKELY(x) (x)
#endif
#include <stddef.h>
/* Macro used for branch prediction. */
#if defined(__GNUC__) || defined(__clang__)
  #define NELUA_LIKELY(x) __builtin_expect(x, 1)
#else
  #define NELUA_LIKELY(x) (x)
#endif
/* Macro used to export C functions. */
#ifdef _WIN32
  #define NELUA_CEXPORT __declspec(dllexport)
#elif defined(__GNUC__)
  #define NELUA_CEXPORT __attribute__((visibility("default")))
#else
  #define NELUA_CEXPORT
#endif
#include <stdio.h>
#include <stdlib.h>
/* Macro used to import/export extern C functions. */
#ifdef __cplusplus
  #define NELUA_EXTERN extern "C"
#else
  #define NELUA_EXTERN extern
#endif
/* Macro used to generate traceback on aborts when sanitizing. */
#if defined(__clang__) && defined(__has_feature)
  #if __has_feature(undefined_behavior_sanitizer)
    #define NELUA_UBSAN_UNREACHABLE __builtin_unreachable
  #endif
#elif defined(__gnu_linux__) && defined(__GNUC__) && __GNUC__ >= 5
  NELUA_EXTERN void __ubsan_handle_builtin_unreachable(void*) __attribute__((weak));
  #define NELUA_UBSAN_UNREACHABLE() {if(&__ubsan_handle_builtin_unreachable) __builtin_unreachable();}
#endif
#ifndef NELUA_UBSAN_UNREACHABLE
  #define NELUA_UBSAN_UNREACHABLE()
#endif
/* Macro used to specify a function that never returns. */
#if __STDC_VERSION__ >= 201112L
  #define NELUA_NORETURN _Noreturn
#elif defined(__GNUC__)
  #define NELUA_NORETURN __attribute__((noreturn))
#elif defined(_MSC_VER)
  #define NELUA_NORETURN __declspec(noreturn)
#else
  #define NELUA_NORETURN
#endif
/* ------------------------------ DECLARATIONS ------------------------------ */
typedef struct nelua_span_uint8_ nelua_span_uint8_;
typedef uint8_t* nluint8_arr0_ptr;
struct nelua_span_uint8_ {
  nluint8_arr0_ptr data;
  uintptr_t size;
};
static NELUA_INLINE intptr_t nelua_span_uint8____len(nelua_span_uint8_ self);
typedef struct nlniltype {} nlniltype;
typedef struct nlniltype nltype;
typedef struct NELUA_MAYALIAS nluint8_arr32 {uint8_t v[32];} nluint8_arr32;
typedef union NELUA_MAYALIAS nluint8_arr32_cast {nluint8_arr32 a; uint8_t p[32];} nluint8_arr32_cast;
static nluint8_arr32 RIV_DEVICE_MAGIC = {.v = {0x3fU, 0xdfU, 0x37U, 0x1eU, 0xc0U, 0xfcU, 0xd1U, 0xbaU, 0xecU, 0xe9U, 0x72U, 0xa1U, 0xf5U, 0x89U, 0x87U, 0xc5U, 0x70U, 0xfdU, 0xbeU, 0xc0U, 0xceU, 0xccU, 0x2dU, 0x74U, 0x8dU, 0x45U, 0x39U, 0x62U, 0x49U, 0xb8U, 0x15U, 0x26U}};
static NELUA_INLINE bool nelua_strchar_1_isspace(uint8_t c);
static NELUA_INLINE uint8_t nelua_strchar_1_getbasedigit(uint8_t c);
typedef struct nlmulret_nlboolean_nlint64 {
  bool r1;
  int64_t r2;
} nlmulret_nlboolean_nlint64;
typedef struct nlstring nlstring;
struct nlstring {
  nluint8_arr0_ptr data;
  uintptr_t size;
};
static nlmulret_nlboolean_nlint64 nelua_strconv_str2int(nlstring s, uint64_t base);
static NELUA_INLINE void nelua_memory_zero(void* dest, uintptr_t n);
static NELUA_INLINE void nelua_memory_spancopy_1(nelua_span_uint8_ dest, nelua_span_uint8_ src);
static int64_t get_free_hugepages(void);
static NELUA_INLINE nlstring nelua_cstring2string(const char* s);
typedef struct riv_context riv_context;
typedef riv_context* riv_context_ptr;
typedef struct riv_desc riv_desc;
typedef riv_desc* riv_desc_ptr;
struct riv_context {
  riv_desc_ptr desc;
  bool running;
  int32_t yield_fd;
  int32_t mem_fd;
  nelua_span_uint8_ audiobuffer;
  nelua_span_uint8_ framebuffer;
};
typedef struct riv_audio_ctl_desc riv_audio_ctl_desc;
typedef uint32_t riv_audio_command;
struct riv_audio_ctl_desc {
  riv_audio_command command;
  uint32_t handle_id;
  uint32_t data_size;
  uint32_t volume;
};
typedef struct riv_framebuffer_desc riv_framebuffer_desc;
struct riv_framebuffer_desc {
  uint32_t height;
  uint32_t width;
  uint32_t fps;
  uint32_t pixel_format;
};
typedef struct riv_keystate riv_keystate;
struct riv_keystate {
  uint64_t down_frame;
  uint64_t up_frame;
};
struct riv_desc {
  uint8_t magic[32];
  uint32_t version;
  uint64_t frame;
  riv_audio_ctl_desc audio_ctl;
  riv_framebuffer_desc framebuffer;
  riv_keystate keys[512];
  uint32_t palette[256];
};
NELUA_CEXPORT void riv_init(riv_context_ptr self);
static NELUA_INLINE void nelua_write_stderr(const char* msg, uintptr_t len, bool flush);
static NELUA_NORETURN void nelua_abort(void);
static void nelua_assert_msg_nlvoid(bool cond, nlstring msg);
NELUA_CEXPORT void riv_uninit(riv_context_ptr self);
typedef uint32_t riv_control_reason;
NELUA_CEXPORT void riv_ctl(riv_context_ptr self, riv_control_reason reason);
typedef struct riv_yield_request riv_yield_request;
struct riv_yield_request {
  uint8_t dev;
  uint8_t mode;
  uint16_t reason;
  uint32_t data;
};
NELUA_CEXPORT void riv_present(riv_context_ptr self);
typedef void (*function_5Q91zdYXxcnAtN5rX)(riv_context_ptr);
NELUA_CEXPORT void riv_loop(riv_context_ptr self, function_5Q91zdYXxcnAtN5rX frame_cb);
static uint64_t handle_counter = 0U;
NELUA_CEXPORT uint64_t riv_sound_play_from_memory(riv_context_ptr self, nelua_span_uint8_ data, uint32_t vol);
NELUA_CEXPORT void riv_sound_stop(riv_context_ptr self, uint64_t sound_id);
/* ------------------------------ DEFINITIONS ------------------------------- */
intptr_t nelua_span_uint8____len(nelua_span_uint8_ self) {
  return (intptr_t)self.size;
}
bool nelua_strchar_1_isspace(uint8_t c) {
  return ((c == 32U) || (((uint32_t)c - 9U) < 5));
}
uint8_t nelua_strchar_1_getbasedigit(uint8_t c) {
  uint8_t d = (c - 48U);
  if((d < 10)) {
    return d;
  }
  d = (c - 97U);
  if((d < 26)) {
    return (d + 10);
  }
  d = (c - 65U);
  if((d < 26)) {
    return (d + 10);
  }
  return 255U;
}
nlmulret_nlboolean_nlint64 nelua_strconv_str2int(nlstring s, uint64_t base) {
  if((s.size == 0)) {
    return (nlmulret_nlboolean_nlint64){false, 0};
  }
  uintptr_t pos = 0U;
  while(((pos < s.size) && nelua_strchar_1_isspace(s.data[pos]))) {
    pos = (pos + 1);
  }
  if((pos >= s.size)) {
    return (nlmulret_nlboolean_nlint64){false, 0};
  }
  bool neg = false;
  if((s.data[pos] == 45U)) {
    pos = (pos + 1);
    neg = true;
  } else if((s.data[pos] == 43U)) {
    pos = (pos + 1);
  }
  if((base == 0)) {
    base = 10U;
    if(((s.data[pos] == 48U) && ((pos + 1) < s.size))) {
      uint8_t bc = s.data[(pos + 1)];
      if(((bc == 98U) || (bc == 66U))) {
        base = 2U;
        pos = (pos + 2);
      } else if(((bc == 120U) || (bc == 88U))) {
        base = 16U;
        pos = (pos + 2);
      }
    }
  }
  if((!((base >= 2) && (base <= 36)))) {
    return (nlmulret_nlboolean_nlint64){false, 0};
  }
  uint64_t n = 0U;
  while((pos < s.size)) {
    uint64_t x = (uint64_t)nelua_strchar_1_getbasedigit(s.data[pos]);
    if((x >= base)) {
      break;
    }
    n = ((n * base) + x);
    pos = (pos + 1);
  }
  while(((pos < s.size) && nelua_strchar_1_isspace(s.data[pos]))) {
    pos = (pos + 1);
  }
  if((pos != s.size)) {
    return (nlmulret_nlboolean_nlint64){false, 0};
  }
  if(neg) {
    n = (-n);
  }
  return (nlmulret_nlboolean_nlint64){true, (int64_t)n};
}
void nelua_memory_zero(void* dest, uintptr_t n) {
  if(NELUA_UNLIKELY((n == 0))) {
    return;
  }
  memset(dest, 0, (size_t)n);
}
void nelua_memory_spancopy_1(nelua_span_uint8_ dest, nelua_span_uint8_ src) {
  if(NELUA_LIKELY((src.size > 0))) {
    memcpy((void*)dest.data, (void*)src.data, (size_t)(src.size * 1));
  }
}
nlstring nelua_cstring2string(const char* s) {
  if(s == NULL) {
    return (nlstring){0};
  }
  uintptr_t size = strlen(s);
  if(size == 0) {
    return (nlstring){0};
  }
  return (nlstring){(uint8_t*)s, size};
}
int64_t get_free_hugepages(void) {
  int32_t fd = open((char*)"/sys/kernel/mm/hugepages/hugepages-2048kB/free_hugepages", 0, 0U);
  if((fd < 0)) {
    return 0;
  }
  nluint8_arr32 buf = (nluint8_arr32){0};
  intptr_t nread = read(fd, (void*)(&buf), 32U);
  if((nread <= 0)) {
    { /* defer */
      close(fd);
    }
    return 0;
  }
  nlmulret_nlboolean_nlint64 _asgnret_1 = nelua_strconv_str2int(nelua_cstring2string((char*)(&buf.v[0])), 10U);
  int64_t res = _asgnret_1.r2;
  { /* defer */
    close(fd);
  }
  return res;
}
void nelua_write_stderr(const char* msg, uintptr_t len, bool flush) {
  if(len > 0 && msg) {
    fwrite(msg, 1, len, stderr);
  }
  if(flush) {
    fwrite("\n", 1, 1, stderr);
    fflush(stderr);
  }
}
void nelua_abort(void) {
  NELUA_UBSAN_UNREACHABLE();
  abort();
}
void nelua_assert_msg_nlvoid(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr((const char*)msg.data, msg.size, true);
    nelua_abort();
  }
}
void riv_init(riv_context_ptr self) {
  nelua_assert_msg_nlvoid((!(self->desc != NULL)), ((nlstring){(uint8_t*)"riv already initialized", 23}));
  self->yield_fd = open((char*)"/dev/yield", O_RDWR, 0U);
  nelua_assert_msg_nlvoid((self->yield_fd > 0), ((nlstring){(uint8_t*)"open yield device failed", 24}));
  nelua_assert_msg_nlvoid((get_free_hugepages() == 1), ((nlstring){(uint8_t*)"no free hugepage", 16}));
  int prot = (PROT_READ | PROT_WRITE);
  int flags = ((((MAP_ANONYMOUS | MAP_SHARED) | MAP_FIXED_NOREPLACE) | MAP_POPULATE) | MAP_HUGETLB);
  void* riv_base = (void*)268435456U;
  nelua_assert_msg_nlvoid((mmap(riv_base, 2097152U, prot, flags, -1, 0) == riv_base), ((nlstring){(uint8_t*)"mmap failed", 11}));
  nelua_assert_msg_nlvoid((get_free_hugepages() == 0), ((nlstring){(uint8_t*)"no used hugepage", 16}));
  nelua_memory_zero(riv_base, 2097152U);
  self->desc = ((riv_desc_ptr)268435456U);
  (((nluint8_arr32_cast*)&self->desc->magic)->a) = RIV_DEVICE_MAGIC;
  self->desc->version = 1000U;
  self->desc->framebuffer = (riv_framebuffer_desc){.width = 256U, .height = 256U, .fps = 60U, .pixel_format = 1U};
  self->audiobuffer = (nelua_span_uint8_){.data = ((nluint8_arr0_ptr)268959744U), .size = 524288U};
  self->framebuffer = (nelua_span_uint8_){.data = ((nluint8_arr0_ptr)269484032U), .size = 1048576U};
}
void riv_uninit(riv_context_ptr self) {
  nelua_assert_msg_nlvoid((self->desc != NULL), ((nlstring){(uint8_t*)"riv not initialized", 19}));
  void* riv_base = (void*)268435456U;
  nelua_memory_zero(riv_base, 2097152U);
  nelua_assert_msg_nlvoid((munmap(riv_base, 2097152U) == 0), ((nlstring){(uint8_t*)"munmap failed", 13}));
  nelua_assert_msg_nlvoid((get_free_hugepages() == 1), ((nlstring){(uint8_t*)"no freed hugepage", 17}));
  if((self->yield_fd > 0)) {
    nelua_assert_msg_nlvoid((close(self->yield_fd) >= 0), ((nlstring){(uint8_t*)"close yield fd failed", 21}));
  }
  (*self) = (riv_context){0};
}
void riv_ctl(riv_context_ptr self, riv_control_reason reason) {
  nelua_assert_msg_nlvoid((self->desc != NULL), ((nlstring){(uint8_t*)"riv not initialized", 19}));
  riv_yield_request swap_yield_req = (riv_yield_request){.dev = 2U, .mode = 0x0U, .reason = (uint16_t)reason, .data = 0U};
  nelua_assert_msg_nlvoid((ioctl(self->yield_fd, 3221803264ULL, (uintptr_t)(&swap_yield_req)) == 0), ((nlstring){(uint8_t*)"yield ioctl failed", 18}));
}
void riv_present(riv_context_ptr self) {
  riv_ctl(self, 1U);
  self->desc->frame = (self->desc->frame + 1);
}
void riv_loop(riv_context_ptr self, function_5Q91zdYXxcnAtN5rX frame_cb) {
  nelua_assert_msg_nlvoid((self->desc != NULL), ((nlstring){(uint8_t*)"riv not initialized", 19}));
  self->running = true;
  while(self->running) {
    frame_cb(self);
    riv_present(self);
  }
}
uint64_t riv_sound_play_from_memory(riv_context_ptr self, nelua_span_uint8_ data, uint32_t vol) {
  handle_counter = (handle_counter + 1);
  uint64_t id = handle_counter;
  nelua_memory_spancopy_1(self->audiobuffer, data);
  self->desc->audio_ctl = (riv_audio_ctl_desc){.command = 1U, .handle_id = (uint32_t)id, .data_size = (uint32_t)nelua_span_uint8____len(data)};
  riv_ctl(self, 2U);
  return id;
}
void riv_sound_stop(riv_context_ptr self, uint64_t sound_id) {
  self->desc->audio_ctl = (riv_audio_ctl_desc){.command = 2U, .handle_id = (uint32_t)sound_id};
  riv_ctl(self, 2U);
}