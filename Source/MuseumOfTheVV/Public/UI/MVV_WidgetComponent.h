// Copyright Virtuous Vagrant

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "MVV_WidgetComponent.generated.h"


class UMVV_AttributeSet;
class UMVV_AbilitySystemComponent;
class AMVV_BaseCharacter;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MUSEUMOFTHEVV_API UMVV_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	/* ### 1. `TObjectPtr<T>` (Strong Reference)
	 *	Introduced in Unreal Engine 5, `TObjectPtr` is the modern replacement for raw pointers (`T*`) when declaring object properties in header files.
	 *	- **Garbage Collection:** When marked with a `UPROPERTY()` macro, it creates a **strong reference**. It tells the Garbage Collector: _"I am actively using this object; do not destroy it."_ As long as the `TObjectPtr` exists and points to the object, the object will stay in memory.
	 *	- **Features:** Under the hood, it provides extra features for the editor, such as access tracking and lazy-loading of assets, which helps optimize memory and loading times.
	 *	- **When to use:** Use it when your class **owns** the object, or when you absolutely require the referenced object to stay alive as long as your class is alive.
	 *
	 *	### 2. `TWeakObjectPtr<T>` (Weak Reference)
	 *	A weak pointer is used to safely reference an object without claiming ownership of it.
	 *	- **Garbage Collection:** It creates a **weak reference**. It tells the Garbage Collector: _"I am looking at this object, but if someone else decides to destroy it, that's fine."_ It will **not** prevent the Garbage Collector from cleaning up the object.
	 *	- **Safety:** If the object it points to is destroyed, the `TWeakObjectPtr` does not become a dangerous "dangling pointer" that crashes your game. Instead, it safely becomes stale. You can check if the object still exists by calling `IsValid()` and access it via `Get()`.
	 *	- **When to use:** Use it when you need to cache a reference to an object that you **do not own** and whose lifetime is managed elsewhere.
	 *
	 *	### Summary: Which one should you use?
	 *	- Use **`TObjectPtr`** (with `UPROPERTY`) for objects you spawn, create, or logically own (e.g., an Inventory Component attached to a Character).
	 *	- Use **`TWeakObjectPtr`** to simply "know about" an object that might disappear at any time (e.g., keeping track of the last enemy that attacked you, or caching a reference to the Player Character inside a UI Widget).
	 */
	
	// So, we are using Weak Object Pointers here because the Character, ASC and AttributeSet
	// are owned by the Player State and Enemy Character, we are just glancing at them,
	// for the sake of our widget.
	TWeakObjectPtr<AMVV_BaseCharacter> Character;
	TWeakObjectPtr<UMVV_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UMVV_AttributeSet> AttributeSet;


	void InitAbilitySystemData();
	bool IsASCInitialized() const;
	void InitializeAttributeDelegate();

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UFUNCTION()
	void BindToAttributeChanges();
};
