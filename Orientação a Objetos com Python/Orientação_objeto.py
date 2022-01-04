class Retangulo:
    def __init__(self, altura, largura):
        #Inicializa a classe com seus atributos/parâmetro
        self.__altura = altura  # inicializando o parâmetro altura como variável privada
        self.largura = largura

    def calculaPerimetro(self):
        #Método que calcula perímetro da classe Retangulo
        p = (2*self.__altura) + (2*self.largura)
        return p

    def getAltura(self):
        #Retorna a altura do objeto da classe Retangulo
        return self.__altura

    def setALtura(self, nova_altura):
        #Atualiza valor do parâmetro altura da classe Retangulo
        self.__altura = nova_altura

    def calculaArea(self):
        #Calcula a área do objeto da classe Retangulo
        area = self.__altura * self.largura
        return area


class Quadrado(Retangulo):
    def __init__(self, altura, largura):
        super().__init__(altura, largura)  # inicializa os parâmetros da classe mãe


class Losango(Retangulo):
    def __init__(self, altura, largura):
        super().__init__(altura, largura)
        self.altura = altura
        self.largura = largura

    def calculaArea(self):
        #Sobrescreve o método calculaArea() (polymorphism Method Overriding)
        area = (self.altura * self.largura)/2
        return area


retangulo = Retangulo(3, 4)
print(retangulo.getAltura())
retangulo.setALtura(5)
print(retangulo.getAltura())

print(retangulo.calculaPerimetro())
print(retangulo.calculaArea())

quadrado = Quadrado(3, 3)
print(quadrado.calculaArea())
print(quadrado.calculaPerimetro())

losango = Losango(3, 4)
print(losango.calculaArea())