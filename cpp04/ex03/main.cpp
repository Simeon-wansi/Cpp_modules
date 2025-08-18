/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:05:18 by sngantch          #+#    #+#             */
/*   Updated: 2025/08/18 22:30:46 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
// int main()
// {
//     IMateriaSource* src = new MateriaSource();
    
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
    
//     ICharacter* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
    
//     return 0;
// }



void testBasicFunctionality() {
    std::cout << "\n=== BASIC FUNCTIONALITY TEST ===" << std::endl;
    
    // Test MateriaSource
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Test Character creation
    ICharacter* alice = new Character("Alice");
    ICharacter* bob = new Character("Bob");
    
    std::cout << "\nCharacter names:" << std::endl;
    std::cout << "Character 1: " << alice->getName() << std::endl;
    std::cout << "Character 2: " << bob->getName() << std::endl;
    
    // Test materia creation and equipping
    std::cout << "\n--- Creating and Equipping Materias ---" << std::endl;
    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");
    AMateria* ice2 = src->createMateria("ice");
    AMateria* cure2 = src->createMateria("cure");
    
    alice->equip(ice1);
    alice->equip(cure1);
    alice->equip(ice2);
    alice->equip(cure2);
    
    // Test using materias
    std::cout << "\n--- Using Materias ---" << std::endl;
    alice->use(0, *bob);  // Ice
    alice->use(1, *bob);  // Cure
    alice->use(2, *bob);  // Ice
    alice->use(3, *bob);  // Cure
    
    delete alice;
    delete bob;
    delete src;
}

void testInventoryLimits() {
    std::cout << "\n=== INVENTORY LIMITS TEST ===" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* character = new Character("TestChar");
    
    std::cout << "\n--- Testing 4-slot inventory limit ---" << std::endl;
    // Fill all 4 slots
    for (int i = 0; i < 4; i++) {
        AMateria* materia = src->createMateria("ice");
        character->equip(materia);
        std::cout << "Equipped slot " << i << std::endl;
    }
    
    // Try to equip 5th materia (should fail silently)
    std::cout << "\n--- Trying to equip 5th materia (should fail) ---" << std::endl;
    AMateria* extraMateria = src->createMateria("cure");
    character->equip(extraMateria);
    
    // Since it wasn't equipped, we need to delete it manually
    delete extraMateria;
    
    delete character;
    delete src;
}

void testUnequipFunction() {
    std::cout << "\n=== UNEQUIP FUNCTION TEST ===" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* character = new Character("UnequipTest");
    ICharacter* target = new Character("Target");
    
    // Equip some materias
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    character->equip(ice);
    character->equip(cure);
    
    std::cout << "\n--- Before unequip ---" << std::endl;
    character->use(0, *target);  // Should work
    character->use(1, *target);  // Should work
    
    std::cout << "\n--- After unequipping slot 0 ---" << std::endl;
    // Save reference before unequipping (to avoid memory leak)
    character->unequip(0);
    character->use(0, *target);  // Should do nothing
    character->use(1, *target);  // Should still work
    
    // Note: In real implementation, you'd need to save the materia pointer
    // before unequipping to avoid memory leaks
    delete ice;  // Clean up the unequipped materia
    
    delete character;
    delete target;
    delete src;
}

void testInvalidOperations() {
    std::cout << "\n=== INVALID OPERATIONS TEST ===" << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    
    ICharacter* character = new Character("ErrorTest");
    ICharacter* target = new Character("Target");
    
    std::cout << "\n--- Testing invalid use indices ---" << std::endl;
    character->use(-1, *target);   // Invalid index
    character->use(5, *target);    // Invalid index
    character->use(0, *target);    // Empty slot
    
    std::cout << "\n--- Testing invalid unequip indices ---" << std::endl;
    character->unequip(-1);        // Invalid index
    character->unequip(5);         // Invalid index
    
    std::cout << "\n--- Testing unknown materia type ---" << std::endl;
    AMateria* unknown = src->createMateria("fire");  // Should return NULL
    if (unknown == NULL) {
        std::cout << "Correctly returned NULL for unknown type" << std::endl;
    }
    
    delete character;
    delete target;
    delete src;
}

void testMateriaSourceLimits() {
    std::cout << "\n=== MATERIA SOURCE LIMITS TEST ===" << std::endl;
    
    MateriaSource* src = new MateriaSource();
    
    std::cout << "\n--- Learning 4 materias (limit) ---" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    std::cout << "\n--- Trying to learn 5th materia (should fail) ---" << std::endl;
    AMateria* extraMateria = new Ice();
    src->learnMateria(extraMateria);
    // Since learning failed, we need to delete the materia
    delete extraMateria;
    
    delete src;
}

void testCopyConstructors() {
    std::cout << "\n=== COPY CONSTRUCTORS TEST ===" << std::endl;
    
    // Test Character deep copy
    std::cout << "\n--- Testing Character deep copy ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    Character original("Original");
    original.equip(src->createMateria("ice"));
    original.equip(src->createMateria("cure"));
    
    Character copy = original;  // Copy constructor
    
    std::cout << "Original name: " << original.getName() << std::endl;
    std::cout << "Copy name: " << copy.getName() << std::endl;
    
    ICharacter* target = new Character("Target");
    
    std::cout << "\nOriginal uses materias:" << std::endl;
    original.use(0, *target);
    original.use(1, *target);
    
    std::cout << "\nCopy uses materias:" << std::endl;
    copy.use(0, *target);
    copy.use(1, *target);
    
    delete target;
    delete src;
}

void testCloneFunction() {
    std::cout << "\n=== CLONE FUNCTION TEST ===" << std::endl;
    
    std::cout << "\n--- Testing Ice clone ---" << std::endl;
    Ice original;
    AMateria* cloned = original.clone();
    
    std::cout << "Original type: " << original.getType() << std::endl;
    std::cout << "Cloned type: " << cloned->getType() << std::endl;
    
    ICharacter* target = new Character("CloneTarget");
    
    std::cout << "\nOriginal use:" << std::endl;
    original.use(*target);
    
    std::cout << "\nCloned use:" << std::endl;
    cloned->use(*target);
    
    delete cloned;
    delete target;
}

int main() {
    std::cout << "Comprehensive Tests" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    testBasicFunctionality();
    testInventoryLimits();
    testUnequipFunction();
    testInvalidOperations();
    testMateriaSourceLimits();
    testCopyConstructors();
    testCloneFunction();
    
    std::cout << "\n=========================================" << std::endl;
    std::cout << "All tests completed!" << std::endl;
    
    return 0;
}