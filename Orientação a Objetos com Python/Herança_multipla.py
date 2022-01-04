class Identidade:                   
    def __init__(self, nome, id): 
        self.nome = nome 
        self.id = id
    
    def printNameId(self):
        print("\nNome: {}\nID: {}".format(self.nome, self.id))

  
class Emprego:                 
    def __init__(self, salario, titulo): 
        self.salario = salario 
        self.titulo = titulo
    
    def printPayTitle(self):
        print("salário: {}\ntitulo: {}".format(self.salario, self.titulo))


class Lider(Identidade, Emprego):      #Herança múltipla
    def __init__(self, nome, id, salario, titulo, exp): 
        self.exp = exp 
        Identidade.__init__(self, nome, id) 
        Emprego.__init__(self, salario, titulo)

    def printExperience(self):
        print("Anos de experiencia: {}".format(self.exp))
        

lider = Lider('Elder', 20090617, 250000, 'Full stack developer', 2)
lider.printNameId()
lider.printPayTitle()
lider.printExperience()
print("\n")