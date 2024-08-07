# C++ module 03

## Table of contents

## Inheritance
```cpp
class Quadruped
{
	private:
		std::string	name;	// Only accessible from an Quadruped object
	protected:
		int			legs;	// Accessible from Quadruped and derived classes
	public:
		void		run();	// Accessible from anywhere
	
	// Here can access name, run() and legs
};

class Dog : public Quadruped
{
	// Can access name, run() and legs
};

int	main(void)
{
	// Can access run()
}
```

## Exercice 00
### Instructions
Files to turn in : Makefile, main.cpp, ClapTrap.hpp, ClapTrap.cpp ScavTrap.hpp, ScavTrap.cpp

Because you can never have enough ClapTraps, you will now create a derived robot. It will be named **ScavTrap** and will inherit the constructors and destructor from Clap- Trap. However, its constructors, destructor and attack() will print different messages. After all, ClapTraps are aware of their individuality.

Note that proper construction/destruction chaining must be shown in your tests. When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order. Why?

**ScavTrap** will use the attributes of ClapTrap (update ClapTrap in consequence) and must initialize them to :
- Name, which is passed as parameter to a constructor
* Hit points (100), represent the health of the ClapTrap
* Energy points (50)
* Attack damage (20)

ScavTrap will also have its own special capacity :
- void guardGate();

This member function will display a message informing that ScavTrap is now in Gate keeper mode.

Don’t forget to add more tests to your program.

### Let's understand the subject
- We have to create a class named **ScavTrap** that will inherit from **ClapTrap**.
- **ScavTrap** will have a constructor that will initialize the attributes of **ClapTrap** and its own attributes.
- **ScavTrap** will have a member function named **guardGate()** that will display a message informing that **ScavTrap** is now in Gate keeper mode.

### How to do it
- Create a class named **ScavTrap** that will inherit from **ClapTrap**.
- Create a constructor that will initialize the attributes of **ClapTrap** and its own attributes.
- Create a member function named **guardGate()** that will display a message informing that **ScavTrap** is now in Gate keeper mode.

```cpp
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void guardGate();
};
```

We have to update the **ClapTrap** class to have a constructor that will initialize the attributes of **ClapTrap**.
``` cpp
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ClapTrap " << this->name << " is created" << std::endl;
}
```

```cpp
class ClapTrap
{
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
	public:
		ClapTrap(std::string name);
		virtual ~ClapTrap();
};
```

