// Fill out your copyright notice in the Description page of Project Settings.

#include "TPT.h"
#include "UniversalFunctions.h"
#include "Warrior.h"
#include "Weapon_Base.h"
#include "SingleInterfaceActor.h"
#include "CustomHud.h"
#include "MyGameMode.h"
#include "C_PlayerController.h"
#include "UI/CookbooStyle.h"



AMyGameMode::AMyGameMode()
{
	//HUDClass = ACustomHud::StaticClass();
	PlayerControllerClass = AC_PlayerController::StaticClass();

}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	CreateStylizedButton();
}

void AMyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(HUDToggleTimer);
	FCookbookStyle::ShutDown();
}

void AMyGameMode::FindActorsUsingInerface()
{
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor* Actor = *It;
		ITestInterface* MyInterfaceInstance = Cast<ITestInterface>(Actor);
		if (MyInterfaceInstance)
		{
			UUniversalFunctions::PrintMsg(FString::Printf(TEXT("%s is the actor"), *(Actor->GetName())));

			MyInterfaceInstances.Add(Actor);
		}
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, FString::Printf(TEXT("%d actors implement thie interface"), MyInterfaceInstances.Num()));
	}

}

void AMyGameMode::createBlinkingButtion()
{
	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(SButton).Content()
			[
				SNew(STextBlock).Text(FText::FromString(TEXT("Test Button")))
			]
		];
	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1);
	GetWorld()->GetTimerManager().SetTimer(HUDToggleTimer, FTimerDelegate::CreateLambda
	([this]
	{
		if (this->Widget->GetVisibility().IsVisible())
		{
			this->Widget->SetVisibility(EVisibility::Hidden);
		}
		else
		{
			this->Widget->SetVisibility(EVisibility::Visible);
		}
	})
		, 5, true);
}

FReply AMyGameMode::ButtonClicked()
{
	ButtonLabel->SetText(FString(TEXT("Clicked")));
	return FReply::Handled();
}

void AMyGameMode::createClickableButton()
{
	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(SButton).OnClicked(FOnClicked::CreateUObject(this, &AMyGameMode::ButtonClicked))
			.Content()
		[
			SAssignNew(ButtonLabel, STextBlock).Text(FText::FromString(TEXT("Click me!")))
		]
		];

	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1);
	}
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	if (GEngine)
	{
		GEngine->GetFirstLocalPlayerController(GetWorld())->SetInputMode(FInputModeUIOnly().SetLockMouseToViewport(false).SetWidgetToFocus(Widget));
	}
}

FText AMyGameMode::GetButtonLabel() const
{
	FVector ActorLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	return FText::FromString(FString::Printf(TEXT("%f, %f, %f"), ActorLocation.X, ActorLocation.Y, ActorLocation.Z));
}

void AMyGameMode::CreateAButtonShowsPlayerPosition()
{
	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(SButton).Content()
			[
				//this looks complicated, but what it is doing is comparatively simple, we assign a TAttribute<FText> to the text property
				//the reason we use TAttribute<FText> instead of just a FText, is because TAttribute<typename T> have a Get() member that can be called to
				//update the value it contains. so the textblock will actually call AmyGameMode::GetbuttonLabel() every frame to update it's Text attribute.

				//To create a TAttribute, we need to call the staitc member TAttribute<typename T>::Create(), which expects a delegate type of your choice. depending on 
				//the type of delegate passed to TAttribute::Create, TAttribute::Get() invokes a different type of function to retrive the vaule to update.

				//in the definition of TAttribute:
				/*template <typename ObjectType>
				class TAttribute
				{
				public:
				DECLARE_DELEGATE_RetVal(ObjectType, FGetter);
				}
				*/
				// the FGetter Delegate type is declared inside the TAttribute class, so it's return value can be templated on the ObjectType parameter of the TAttribute template
				SNew(STextBlock).Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(this, &AMyGameMode::GetButtonLabel)))
			]
		];
	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1);
	}
}

void AMyGameMode::CreateStylizedButton()
{
	FCookbookStyle::Initialize();
	Widget = SNew(SVerticalBox) + SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(SButton).ButtonStyle(FCookbookStyle::Get(), "NormalButtonBrush").ContentPadding(FMargin(16)).Content()
			[
				SNew(STextBlock)
				.TextStyle(FCookbookStyle::Get(), "NormalButtonText")
		.Text(FText::FromString("Styled Button"))
			]
		];
	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(), Widget.ToSharedRef(), 1);
	}
}

