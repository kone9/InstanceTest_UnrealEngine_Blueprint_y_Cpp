// Fill out your copyright notice in the Description page of Project Settings.



#include "instanciarCubosCPP.h"



// Sets default values for this component's properties
UinstanciarCubosCPP::UinstanciarCubosCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UinstanciarCubosCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	vacio = GetOwner();
	posicion.X = vacio->GetActorLocation().X;
	posicion.Y = vacio->GetActorLocation().Y + 5;
	posicion.Z = vacio->GetActorLocation().Z;
	
	

	GetWorld()->GetTimerManager().SetTimer(Tiempo,this, &UinstanciarCubosCPP::InstanciarCuboCadaCiertoTiempo,tiempoParaInstanciar,true,tiempoAntesDeEmpezarAInstanciar);
}


// Called every frame
void UinstanciarCubosCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UinstanciarCubosCPP::InstanciarCuboCadaCiertoTiempo()
{
	
	GetWorld()->SpawnActor(cuboAinstanciar, &posicion, &rotacion);
	contador += 1;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%i"), contador));
}

