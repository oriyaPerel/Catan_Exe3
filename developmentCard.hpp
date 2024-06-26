#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP
enum class ResourceType;
#include <iostream>
#include "Player.hpp"
#include "Hexigon.hpp"
// id:322522806
// email:oriyaperel18@gmail.com

enum class CardType
{
    Knight,
    Monopoly,
    YearOfPlenty,
    VictoryPoint,
    RoadBuilding
};

class developmentCard
{
public:
    bool isBought = false;
    virtual ~developmentCard();
    virtual void active(Player *player) = 0;
    void startActive(Player *player);
    void setBought(bool isBought) { this->isBought = isBought; }
    bool getIsBought() const { return isBought; }
};

class Monopoly : public developmentCard
{
private:
    std::vector<Player *> players;
    ResourceType resource = ResourceType::None;

public:
    Monopoly(std::vector<Player *> players);
    ~Monopoly();
    void active(Player *player) override;
    void setResource(ResourceType resource);
};

class VictoryPoint : public developmentCard
{
public:
    ~VictoryPoint();
    void active(Player *player) override;
};

class RoadBuilding : public developmentCard
{
public:
    ~RoadBuilding();
    void active(Player *player) override;
};

class YearOfPlenty : public developmentCard
{
private:
    ResourceType resource1 = ResourceType::None;
    ResourceType resource2 = ResourceType::None;

public:
    void setResources(ResourceType resource1, ResourceType resource2);
    ~YearOfPlenty();
    void active(Player *player) override;
};

class Knight : public developmentCard
{
public:
    ~Knight();
    void active(Player *player) override;
};

#endif
