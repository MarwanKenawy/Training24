#Parent
class Villain():
    def __init__(self,health = 100,energy = 500,shield = 0):
        self.health = health
        self.energy = energy
        self.shield = shield
    def checkEnergy(self):
        return self.energy
    def checkHealth(self):
        return self.health

#Parent
class Gadget():
    def __init__(self,name,energy,resources = -1):
        self.name = name
        self.energy = energy
        self.resources = resources
    def __str__(self):
        return f"{self.name}"
    def checkResources(self):
        return self.resources
    def checkEnergy(self):
        return self.energy

#child
class Weapon(Gadget):
    def __init__(self,name,energy,damage,resources = -1):
        super().__init__(name,energy,resources)
        self.damage = damage
    def attack(self,controller1,controller2):
        controller1.energy -= self.energy
        if(self.name == "KalmanMissile"):
                controller2.shield = 0
        controller2.health -= (self.damage)*(1 - controller1.damageReduction)*(1-controller2.shield)
        controller2.shield = 0
        if(self.name == "MegaMagnet"):
            controller2.damageReduction = 0.2
        controller1.damageReduction = 0
        if(self.resources>0):
            self.resources -= 1

#child
class Shield(Gadget):
    def __init__(self,name,energy,save,resources = -1):
        super().__init__(name,energy,resources)
        self.save = save/100
    def defense(self,controller1):
        controller1.energy -= self.energy
        controller1.shield = self.save
        if(self.resources>0):
            self.resources -= 1

#child
class Gru(Villain):
    damageReduction = 0
    def __init__(self):
        super().__init__()
    FreezeGun = Weapon("FreezeGun",50,11)
    ElectricProd = Weapon("ElectricProd",88,18,5)
    MegaMagnet = Weapon("MegaMagnet",92,10,3)
    KalmanMissile = Weapon("KalmanMissile",120,20,1)
    EnergyProjectedBarrierGun = Shield("EnergyProjectedBarrierGun",20,40)
    SelectivePermeability = Shield("SelectivePermeability",50,90,2)
    move_pool = {'1':FreezeGun,'2':ElectricProd,'3':MegaMagnet,'4':KalmanMissile,'5':EnergyProjectedBarrierGun,'6':SelectivePermeability}
    minEnergy = FreezeGun.energy
    for gadget in move_pool:
        if(move_pool[gadget].checkEnergy() < minEnergy):
            minEnergy = move_pool[gadget].checkEnergy()
    def checkMinEnergy(self):
        return self.minEnergy

#child
class Vector(Villain):
    damageReduction = 0
    def __init__(self):
        super().__init__()
    LaserBlaster = Weapon("LaserBlaster",40,8)
    PlasmaGrenades = Weapon("PlasmaGrenades",56,13,8)
    SonicResonanceCannon = Weapon("SonicResonanceCannon",100,22,3)
    EnergyNetTrap = Shield("EnergyNetTrap",15,32)
    QuantumDeflector = Shield("QuantumDeflector",40,80,3)
    move_pool = {'1':LaserBlaster,'2':PlasmaGrenades,'3':SonicResonanceCannon,'4':EnergyNetTrap,'5':QuantumDeflector}
    minEnergy = LaserBlaster.energy
    for gadget in move_pool:
        if(move_pool[gadget].energy < minEnergy):
            minEnergy = move_pool[gadget].energy
    def checkMinEnergy(self):
        return self.minEnergy
