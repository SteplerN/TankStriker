export module Animation;

import std;
import sfml;

import Usings;
import Entity;
import Enums;

export class Animation : public Entity
{

protected:

	TimeListCollection m_TimeList;

	sf::Clock m_TimeFromStart;
	sf::Clock m_TimeFromCurrentFrameStartedPlaying;

	int16_t m_HowManyTimesPlayed = 0;

	bool m_IsAnimationPlaying = false;
	bool m_IsDisappearing = false;

	void doAnimationRoutine() override {}

public:

	virtual void finishIterationOfAnimation() = 0;

	void doRoutine([[maybe_unused]] float p_Time, [[maybe_unused]] float p_DeltaTime) override
	{
		doAnimationRoutine();
	}

	void playAnimation()
	{
		m_CurrentFrameNumber = 0;
		m_IsAnimationPlaying = true;
		m_TimeFromStart.restart();
		m_TimeFromCurrentFrameStartedPlaying.restart();
	}

	~Animation() override = default;
};