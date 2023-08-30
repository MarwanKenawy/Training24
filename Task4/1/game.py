import sys
from characters import *


class Game():
    #To check Health of each player and Energy
    def hp_energy_check(self,controller_1, controller_2):
        if controller_1.checkHealth() <= 0:
            if controller_2.checkHealth() >0:
                print ("Player 2 Wins!")
                sys.exit()
            else:
                print ("It's a Draw!!!")
                sys.exit()
        elif controller_2.checkHealth() <= 0:
            print ("Player 1 Wins!")
            sys.exit()
        #if the players ran out of energy
        if((controller_1.checkEnergy() < controller_1.checkMinEnergy()) and (controller_2.checkEnergy() < controller_2.checkMinEnergy())):
            print("No energy Game ends\n\n")
            if(controller_1.checkHealth()>controller_2.checkHealth()):
                print ("Player 1 Wins!")
                sys.exit()
            elif(controller_1.checkHealth() < controller_2.checkHealth()):
                print ("Player 2 Wins!")
                sys.exit()
            else:
                print ("It's a Draw!!!")
                sys.exit()

    #choosng Gadget (Weapon,Shield)
    def player_choose_move(self,controller,controller_index):
        while True:
            print("Player "+ str(controller_index) + ", choose your move:")
            for gadget in controller.move_pool:
                if(type(controller.move_pool[gadget]) == Weapon):
                    print(f"{gadget}) {controller.move_pool[gadget]} (Weapon) Energy:{controller.move_pool[gadget].energy} Damage:{controller.move_pool[gadget].damage}")
                else:
                    print(f"{gadget}) {controller.move_pool[gadget]} (Shield) Energy:{controller.move_pool[gadget].energy} Save:{controller.move_pool[gadget].save*100}%")
            
            if(controller.energy<controller.minEnergy):
                #if player has energy less than the minimum energy required for any gadget Then he can't pick a gadget
                print("No enough Energy")
                controller.move = None
                return None
            
            move_choice = input()
            
            try:
                controller.move = controller.move_pool[move_choice]
            except KeyError:
                print ("Please choose one of the listed options.\n")
                continue
            if(controller.move.checkResources() == -1 or controller.move.checkResources() > 0):
                if(controller.move.checkEnergy()<=controller.checkEnergy()):
                    return None
                else:
                    print("Not enough Energy")
            else:
                print("Not enough resources")
    #updating players status
    def update(self,controller1,controller2):
        print ("=== Player1 HP:", str(controller1.health)," Energy: ",str(controller1.energy), "===\n")
        print ("=== Player2 HP:", str(controller2.health)," Energy: ",str(controller2.energy), "===\n")
        print ("\n\n")
   #The sequence of the game which consists of updating player status on console then each player chooses a move (Gadget)
    def move_collection(self,controller1,controller2):
        self.update(controller1,controller2)
        self.player_choose_move(Player_1,1)
        self.player_choose_move(Player_2,2)
   
   #The fight process (Attacking, Defensing)
    def move_application(self,controller1,controller2):
        if(controller1.move != None and controller2.move != None):#to check that every player chose a move
            if type(controller1.move) == Weapon and type(controller2.move) == Shield:
                controller2.move.defense(controller2)
                controller1.move.attack(controller1,controller2)
            elif type(controller1.move) == Shield and type(controller2.move) == Weapon:
                controller1.move.defense(controller1)
                controller2.move.attack(controller2,controller1)
            elif type(controller1.move) == Shield and type(controller2.move) == Shield:
                controller1.move.defense(controller1)
                controller2.move.defense(controller2)
            elif type(controller1.move) == Weapon and type(controller2.move) == Weapon:
                controller1.move.attack(controller1,controller2)
                controller2.move.attack(controller2,controller1)
        #if any of the players didn't chose a move then the other one will perform his move alone
        elif(controller1.move != None):
            if type(controller1.move) == Weapon:
                controller1.move.attack(controller1,controller2)
            else:
                controller1.move.defense(controller1)
        elif(controller2.move != None):
            if type(controller2.move) == Weapon:
                controller2.move.attack(controller2,controller1)
            else:
                controller2.move.defense(controller2)

#game instance
game = Game()

#player_1 is Gru , Player_2 is Vector
( Player_1, Player_2 ) = ( Gru(), Vector() )
print("Player_1: Gru\nPlayer_2: Vector\n\n")
while True:
    game.move_collection(Player_1,Player_2)
    game.move_application(Player_1,Player_2)
    game.hp_energy_check(Player_1,Player_2)