NAME=doom

OBJS+=\
	am_map.o \
	d_event.o \
	d_items.o \
	d_iwad.o \
	d_loop.o \
	d_main.o \
	d_mode.o \
	d_net.o \
	doomdef.o \
	doomstat.o \
	dstrings.o \
	dummy.o \
	f_finale.o \
	f_wipe.o \
	g_game.o \
	hu_lib.o \
	hu_stuff.o \
	i_cdmus.o \
	i_endoom.o \
	i_joystick.o \
	i_main.o \
	i_scale.o \
	i_system.o \
	i_timer.o \
	info.o \
	m_argv.o \
	m_bbox.o \
	m_cheat.o \
	m_config.o \
	m_controls.o \
	m_fixed.o \
	m_menu.o \
	m_misc.o \
	m_random.o \
	memio.o \
	p_ceilng.o \
	p_doors.o \
	p_enemy.o \
	p_floor.o \
	p_inter.o \
	p_lights.o \
	p_map.o \
	p_maputl.o \
	p_mobj.o \
	p_plats.o \
	p_pspr.o \
	p_saveg.o \
	p_setup.o \
	p_sight.o \
	p_spec.o \
	p_switch.o \
	p_telept.o \
	p_tick.o \
	p_user.o \
	r_bsp.o \
	r_data.o \
	r_draw.o \
	r_main.o \
	r_plane.o \
	r_segs.o \
	r_sky.o \
	r_things.o \
	s_sound.o \
	sha1.o \
	sounds.o \
	st_lib.o \
	st_stuff.o \
	statdump.o \
	tables.o \
	v_video.o \
	w_checksum.o \
	w_file.o \
	w_file_stdc_unbuffered.o \
	w_main.o \
	w_wad.o \
	wi_stuff.o \
	z_zone.o

OBJS+=\
	i_input_riv.o \
	i_rivsound.o \
	i_sound_riv.o \
	i_video_riv.o

include ../demo-c.mk
