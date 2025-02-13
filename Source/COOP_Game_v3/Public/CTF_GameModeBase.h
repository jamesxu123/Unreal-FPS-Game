//CTF_GameModeBase.h
//2019-6-14

//James Xu, Feeda Elahresh, Aaryan Patel
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CTF_PlayerState.h"
#include "CTF_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class COOP_GAME_V3_API ACTF_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, Category = "CTF", meta = (ClampMin = 0))
	float GameDuration; //length of game in seconds

	FTimerHandle TimerHandle_GameEnd;

	void CTFGameStart();

	void CTFGameEnd();
    
    void RestartDeadPlayers();

	int32 RedPlayerCount;

	int32 BluePlayerCount;
    

public:
    
    ACTF_GameModeBase();
    
	virtual void StartPlay() override;

	void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	void FlagCapture(uint8 TeamThatCapturedIt);
    
    virtual void Tick( float DeltaTime ) override;

	virtual AActor* ChoosePlayerStart(AController* Player);;

	bool ShouldSpawnAtStartSpot(AController* Player) override
	{
		return false;
	}
};
