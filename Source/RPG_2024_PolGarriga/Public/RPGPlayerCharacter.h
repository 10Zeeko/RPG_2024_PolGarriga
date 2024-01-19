#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "RPGPlayerCharacter.generated.h"

UCLASS()
class RPG_2024_POLGARRIGA_API ARPGPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGPlayerCharacter();
	
	virtual void Tick(float DeltaTime) override;
	
	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return mpTopDownCameraComponent; }
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return mpCameraBoom; }
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera,meta=(AllowPrivateAccess = "true"))
	UCameraComponent* mpTopDownCameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera,meta=(AllowPrivateAccess = "true"))
	USpringArmComponent* mpCameraBoom;
};
