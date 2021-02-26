// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "instanciarCubosCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INSTANCETEST_API UinstanciarCubosCPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UinstanciarCubosCPP();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> cuboAinstanciar;
	
	AActor* vacio = nullptr;

	UPROPERTY(EditAnywhere)
	FVector posicion;

	UPROPERTY(EditAnywhere)
	FRotator rotacion;
	
	UPROPERTY(EditAnywhere)
	float tiempoParaInstanciar = 1;

	UPROPERTY(EditAnywhere)
	float tiempoAntesDeEmpezarAInstanciar = 0;

	int contador = 0;
	
public:
	void InstanciarCuboCadaCiertoTiempo();

	FTimerHandle Tiempo;
};
