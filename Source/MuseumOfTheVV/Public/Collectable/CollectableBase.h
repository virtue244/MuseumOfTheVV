// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableBase.generated.h"


class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollected, AActor*, CollectedBy);

UCLASS()
class MUSEUMOFTHEVV_API ACollectableBase : public AActor
{
	GENERATED_BODY()

public:
	ACollectableBase();

protected:
	virtual void BeginPlay() override;

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MVV|Components")
	USphereComponent* CollisionComponent;
    
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MVV|Components")
	UStaticMeshComponent* MeshComponent;

    
private:


};
