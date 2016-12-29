// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "CPathFollowingComponent.h"




void UCPathFollowingComponent::FollowPathSegment(float DeltaTime)
{
	Super::FollowPathSegment(DeltaTime);
}

void UCPathFollowingComponent::SetMoveSegment(int32 SegmentStartIndex)
{
	Super::SetMoveSegment(SegmentStartIndex);
}

void UCPathFollowingComponent::UpdatePathSegment()
{
	Super::UpdatePathSegment();
}
