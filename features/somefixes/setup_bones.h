#pragma once

class set_ : public singleton< set_ > {
public:
	void start();
	void recreate(player_t* e);
	matrix3x4_t lag[128];
};

struct anim_state_info_t
{
	CBaseHandle	handle;
	float spawn_time;
	c_baseplayeranimationstate* animstate;
	float animvel;
	std::array<float, 24> poses;
};

struct anim_z
{
	int back_flag;
};

class fix_ : public singleton< fix_ > {
public:
	void start();
	void draw_shit();
	void update();
	void update_custom_anims(player_t* x);
	void update_local_animations();
	void create_anim_state(c_baseplayeranimationstate* state, player_t* player);
	void update_anim_state(c_baseplayeranimationstate* state, Vector angles);
	void update_layer(player_t* x);
	anim_state_info_t anim_info[65];
	matrix3x4_t lag_[128];
	void fix_bones(matrix3x4_t* maxtrix);
	anim_z ok_fix;
};