#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


/*
// Dungeons Game
// A Win32 Console based pseudo-RPG

// Begin LivingThing class
class LivingThing
{
public:
    // Constructors
    LivingThing() {}
    ~LivingThing() {}

    // Accessors
    void DisplayHealth() const { cout << m_Attack; }
    bool IsAlive() const { return m_Alive; }

protected:
    unsigned short m_Attack;
    unsigned short m_Mana;
    short m_Health;
    bool m_Alive;
};
class Skeleton;
// Begin Player class
class Player : public LivingThing
{
public:
    // Constructors
    Player() { m_Attack = 7; m_Health = 30; m_Mana; }
    ~Player() {}

    // Dealing damage and taking damage functions
    void Attack(Skeleton& skeletonInstance);
    void TakeDamage(int damage);
};

// Begin Skeleton class
class Skeleton : public LivingThing
{
public:
    // Constructors
    Skeleton() { m_Attack = 5; m_Health = 10; m_Mana = 0; }
    ~Skeleton() {}

    // Dealing damage and taking damage functions
    void Attack(Player& playerInstance);
    void TakeDamage(int damage);
};

void Player::Attack(Skeleton& skeletonInstance)
{
    cout << "Player attacks 'Skeleton' for " << m_Attack << " damage.";
    skeletonInstance.TakeDamage(m_Attack);
}

void Player::TakeDamage(int damage)
{
    m_Health -= damage;
    if (m_Health <= 0)
    {
        cout << "Player is dead";
        m_Alive = false;
    }
}

void Skeleton::Attack(Player& playerInstance)
{
    cout << "Skeleton attacks 'Player' for " << m_Attack << " damage.";
    playerInstance.TakeDamage(m_Attack);
}

void Skeleton::TakeDamage(int damage)
{
    m_Health -= damage;
    if (m_Health <= 0)
    {
        cout << "Skeleton is dead";
        m_Alive = false;
    }
}


// Main entry point
int main()
{
    enum OBJECTS {player, skeleton};

    short skeletonKillCount = 0;
    // Create a player instance
    Player player1;

    // Create three Skeleton instances
    Skeleton skeleton1;
    Skeleton skeleton2;
    Skeleton skeleton3;
    Skeleton curSkeleton;

    // Run until either player is dead or all 3 skeletons have been defeated
    // Main game loop
    do 
    {
        // Assign the skeleton number to the curSkeleton variable
        if (skeleton1.IsAlive()) {
            Skeleton curSkeleton = skeleton1;
        }
        else if (skeleton2.IsAlive())
        {
            Skeleton curSkeleton = skeleton2;
        }
        else if (skeleton3.IsAlive())
        {
            Skeleton curSkeleton = skeleton3;
        }

        // Perform the actions
        player1.Attack(curSkeleton);
        curSkeleton.Attack(player1);
        system("pause");

        // Display all healths
        player1.DisplayHealth();
        curSkeleton.DisplayHealth();
        
        if (curSkeleton.IsAlive() == false) {
            skeletonKillCount++;
        }

        if (curSkeleton.IsAlive() == false) {
            cout << "You died after killing " << skeletonKillCount << " skeletons. Better luck next time.";
            system("pause");
            return 0;
        }

    } while (skeletonKillCount < 3);

    cout << "You survived! You killed all 3 skeletons with ";
    player1.DisplayHealth();
    cout << " health left.";

    system("pause");
    return 0;
}
*/

int main(){
    srand((unsigned) time(0));
    char card[16] = "";
    for (int i = 0; i < 16; i++)
    {
        card[i] = (rand() %9) + '0';
        
        cout << card[i]<< '\t' <<  endl;
    }
}