// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "CPathFollowingComponent.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FollowerCharacter.h"

#include "CAIController.h"




ACAIController::ACAIController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UCPathFollowingComponent>(TEXT("PathFollowingComponent")))
{
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComp"));
}


void ACAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	AFollowerCharacter* EnemyChar = Cast<AFollowerCharacter>(InPawn);

	if (EnemyChar && EnemyChar->BotBehavior)
	{
		BlackboardComp->InitializeBlackboard(*EnemyChar->BotBehavior->BlackboardAsset);
		
		EnemyKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*EnemyChar->BotBehavior);
	}
}
