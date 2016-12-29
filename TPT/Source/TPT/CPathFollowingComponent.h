// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Navigation/PathFollowingComponent.h"
#include "CPathFollowingComponent.generated.h"

/**
 * 
 */
UCLASS()
class TPT_API UCPathFollowingComponent : public UPathFollowingComponent
{
	GENERATED_BODY()

		//Per tick modification of path following
		//this is how you really customize
		//how unit follow the path!
protected:
	virtual void FollowPathSegment(float DeltaTime) override;
	virtual void SetMoveSegment(int32 SegmentStartIndex) override;
	virtual void UpdatePathSegment() override;
	
	
};
