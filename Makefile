NAME=doom
DEMOLANG=c

OBJS+=\
	build/am_map.o \
	build/d_event.o \
	build/d_items.o \
	build/d_iwad.o \
	build/d_loop.o \
	build/d_main.o \
	build/d_mode.o \
	build/d_net.o \
	build/doomdef.o \
	build/doomstat.o \
	build/dstrings.o \
	build/dummy.o \
	build/f_finale.o \
	build/f_wipe.o \
	build/g_game.o \
	build/hu_lib.o \
	build/hu_stuff.o \
	build/i_cdmus.o \
	build/i_endoom.o \
	build/i_joystick.o \
	build/i_main.o \
	build/i_scale.o \
	build/i_system.o \
	build/i_timer.o \
	build/info.o \
	build/m_argv.o \
	build/m_bbox.o \
	build/m_cheat.o \
	build/m_config.o \
	build/m_controls.o \
	build/m_fixed.o \
	build/m_menu.o \
	build/m_misc.o \
	build/m_random.o \
	build/memio.o \
	build/p_ceilng.o \
	build/p_doors.o \
	build/p_enemy.o \
	build/p_floor.o \
	build/p_inter.o \
	build/p_lights.o \
	build/p_map.o \
	build/p_maputl.o \
	build/p_mobj.o \
	build/p_plats.o \
	build/p_pspr.o \
	build/p_saveg.o \
	build/p_setup.o \
	build/p_sight.o \
	build/p_spec.o \
	build/p_switch.o \
	build/p_telept.o \
	build/p_tick.o \
	build/p_user.o \
	build/r_bsp.o \
	build/r_data.o \
	build/r_draw.o \
	build/r_main.o \
	build/r_plane.o \
	build/r_segs.o \
	build/r_sky.o \
	build/r_things.o \
	build/s_sound.o \
	build/sha1.o \
	build/sounds.o \
	build/st_lib.o \
	build/st_stuff.o \
	build/statdump.o \
	build/tables.o \
	build/v_video.o \
	build/w_checksum.o \
	build/w_file.o \
	build/w_file_stdc_unbuffered.o \
	build/w_main.o \
	build/w_wad.o \
	build/wi_stuff.o \
	build/z_zone.o

OBJS+=\
	build/i_input_riv.o \
	build/i_rivsound.o \
	build/i_rivmusic.o \
	build/i_sound_riv.o \
	build/i_video_riv.o

COMP=zstd -Xcompression-level 22

include ../demo-base.mk

CFLAGS+=-flto=auto
