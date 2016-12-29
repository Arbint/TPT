// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Warrior.h"
#include "CAIController.h"
#include "FollowerCharacter.h"

#include "MyBTService_CheckForPlayer.h"




UMyBTService_CheckForPlayer::UMyBTService_CheckForPlayer()
{
	bCreateNodeInstance = true;
}

void UMyBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ACAIController* EnemyPC = Cast<ACAIController>(OwnerComp.GetAIOwner());
	if (EnemyPC)
	{
		AWarrior* Enemy = Cast<AWarrior>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (Enemy)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyPC->EnemyKeyID, Enemy);
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("ENEMY IS HERE!"));
			}
		}
	}
}
