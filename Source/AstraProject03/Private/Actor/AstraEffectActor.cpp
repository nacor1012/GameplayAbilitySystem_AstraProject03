// Copyright SkyHigh Gaming.


#include "Actor/AstraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AstraAttributeSet.h"
#include "Components/SphereComponent.h"


AAstraEffectActor::AAstraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AAstraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAstraAttributeSet* AstraAttributeSet = Cast<UAstraAttributeSet> (ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAstraAttributeSet::StaticClass()));

		UAstraAttributeSet* MutableAstraAttributeSet = const_cast<UAstraAttributeSet*>(AstraAttributeSet);
		MutableAstraAttributeSet->SetHealth(AstraAttributeSet->GetHealth() + 25.f);
		MutableAstraAttributeSet->SetMana(AstraAttributeSet->GetMana() - 25.f);
		Destroy();
	}
}

void AAstraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AAstraEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAstraEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAstraEffectActor::EndOverlap);
	
}


