export module Enums;

export enum class Direction
{
	Forward,
	Backward,
	Left,
	Right
};

export enum EntityType
{
	Static,
	Animation
};

export enum class AnimationType
{
	Looped,
	Finished
};

export enum class HitBoxType
{
	Collision,
	Damagable,
	Clickable
};