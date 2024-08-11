class Vertice:
    def __init__(self, valor):
        self.valor = valor
        self.rotulo = None

class Aresta:
    def __init__(self, vertice1, vertice2):
        self.vertice1 = vertice1
        self.vertice2 = vertice2

class Arvore:
    def __init__(self):
        self.vertices = []
        self.arestas = []

def criar_nova_arvore(vertice_vk, vertice_wk, aresta, cp, vertex):
    nova_arvore = Arvore()
    vertice_vk.rotulo = cp
    vertice_wk.rotulo = cp
    nova_arvore.vertices.append(vertice_vk)
    nova_arvore.vertices.append(vertice_wk)
    nova_arvore.arestas.append(aresta)
    vertex[vertice_vk.valor] = cp
    vertex[vertice_wk.valor] = cp
    cp += 1
    return nova_arvore, cp

def unir_arvores(arvore_i, arvore_j, aresta, cp, vertex):
    for vertice in arvore_j.vertices:
        vertice.rotulo = cp
        arvore_i.vertices.append(vertice)
        vertex[vertice.valor] = cp
    arvore_i.arestas.append(aresta)
    cp -= 1
    return arvore_i, cp

def adicionar_vertice_e_aresta(arvore, vertice, aresta, cp, vertex):
    vertice.rotulo = cp
    arvore.vertices.append(vertice)
    arvore.arestas.append(aresta)
    vertex[vertice.valor] = cp
    return arvore

def verificar_e_atualizar_arvores(arvores, vk, wk, aresta, cp, vertex):
    pertence_a_arvore_i = False
    pertence_a_arvore_j = False
    arvore_i = None
    arvore_j = None

    if vertex[vk.valor] != 0:
        pertence_a_arvore_i = True
        for arvore in arvores:
            if vertex[vk.valor] == arvore.rotulo:
                arvore_i = arvore

    if vertex[wk.valor] != 0:
        pertence_a_arvore_j = True
        for arvore in arvores:
            if vertex[wk.valor] == arvore.rotulo:
                arvore_j = arvore

    if not pertence_a_arvore_i and not pertence_a_arvore_j:
        nova_arvore, cp = criar_nova_arvore(vk, wk, aresta, cp, vertex)
        arvores.append(nova_arvore)
    elif pertence_a_arvore_i and not pertence_a_arvore_j:
        arvore_i = adicionar_vertice_e_aresta(arvore_i, wk, aresta, cp, vertex)
        cp += 1
    elif not pertence_a_arvore_i and pertence_a_arvore_j:
        arvore_j = adicionar_vertice_e_aresta(arvore_j, vk, aresta, cp, vertex)
        cp += 1
    else:
        arvores.remove(arvore_j)
        arvore_i, cp = unir_arvores(arvore_i, arvore_j, aresta, cp, vertex)

    return arvores, cp

# Lista de arestas representada pelos vetores F e H
F = ['a', 'e', 'i', 'i', 'b', 'b', 'c', 'b', 'f', 'c', 'f', 'a']
H = ['b', 'h', 'b', 'c', 'c', 'e', 'g', 'f', 'g', 'e', 'd', 'c']

arvores = []
cp = 1

# Criando o vetor VERTEX
vertex = {chr(i): 0 for i in range(ord('a'), ord('j'))}

for i in range(len(F)):
    vertice_vk = Vertice(F[i])
    vertice_wk = Vertice(H[i])
    aresta = Aresta(vertice_vk, vertice_wk)
    arvores, cp = verificar_e_atualizar_arvores(arvores, vertice_vk, vertice_wk, aresta, cp, vertex)

# Verificando o resultado
for arvore in arvores:
    print("Arvore:")
    for vertice in arvore.vertices:
        print("Vértice:", vertice.valor, "Rótulo:", vertice.rotulo)
    for aresta in arvore.arestas:
        print("Aresta:", aresta.vertice1.valor, "-", aresta.vertice2.valor)

# Imprimindo o vetor VERTEX
print("\nVetor VERTEX:")
print(vertex)
