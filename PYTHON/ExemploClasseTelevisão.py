class Televisão:
    def __init__(self, pcanal, min, max):
        self.canal = pcanal
        self.cmin = min
        self.cmax = max
        
    def mudar_canal_para_baixo(self):
        if self.canal == self.cmin:
            self.canal = self.cmax
        else:
            self.canal -= 1

    def mudar_canal_para_cima(self):
        if self.canal == self.cmax:
            self.canal = self.cmin
        else:
            self.canal += 1

tv1 = Televisão(2, 0, 10)
print(tv1.canal)
for x in range(1, 20):
    tv1.mudar_canal_para_cima()
    print(tv1.canal)

tv2 = Televisão(10, 0, 10)
for x in range(1,20):
    tv2.mudar_canal_para_baixo()
    print(tv2.canal)