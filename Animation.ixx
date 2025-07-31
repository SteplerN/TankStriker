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

	int32_t m_HowManyTimesPlayed = 0;

	bool m_IsAnimationPlaying = false;
	bool m_IsDisappearing = false;

	virtual void doAnimationRoutine() = 0;

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