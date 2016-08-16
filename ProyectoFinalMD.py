conjuntoA=[] #inicializacion del conjunto universal
conjuntoB=[] # y los subconjuntos a y b
conjuntoU=[]

def conjuntosExpress(): #define una funcion que consigue conjuntos de forma "express"
    print "Ingrese los valores del Conjunto Universal: (Escriba fin en nueva linea al terminar)" #imprime instruccion breve
    item = 'string' #variable item de tipo string
    while 1: #creamos un loop para poder seguir pidiendo valores del conjunto hasta que se escriba fin
        item=raw_input('Valores:')  #raw_input toma lo que se escribe y lo iguala a item como string
        if item=='fin': #en el caso de que se escriba 'fin' se hace un break y deja de igualar valores al conjunto
            break
        for valorInd in item: #para cada caracter en el string escrito
            if valorInd in conjuntoU: #revisa si el caracter existe en el universo
                print valorInd, "ya exite en el Conjunto Universal"
            else: # si no, lo agrega al conjunto
                conjuntoU.append(valorInd)
        print(conjuntoU) #imprime el conjunto universal
    
    print "Ingrese los valores del Conjunto A:" #instruccion para ingresar los valores del subconjunto a
    item = 'string' #igual que arriba
    while 1:
        item = raw_input('Valores:')
        if item=='fin':
            break
        for valorInd in item: # para cada valor del string introducido
            if valorInd in conjuntoU: #revisa si existe en el conkunto universal
                if valorInd in conjuntoA: #revisa si existe en el conjunto A
                    print valorInd, "ya exite en el Conjunto A" #si ya existe, le dice al usuario
                else: # si no, lo agrega al conjunto A
                    conjuntoA.append(valorInd)
            else: #si no existe en el universal, 
                print valorInd, "no existe en el Universo." #le dice al usuario cual valor no existe.
        print(conjuntoA) #imprime el conjunto
    
    print "Ingrese los valores del Conjunto B:" #hace lo mismo que el conjunto A pero para el conjunto B
    item = 'string'
    while 1:
        item = raw_input('Valores:')
        if item=='fin':
            break
        for valorInd in item:
            if valorInd in conjuntoU:
                if valorInd in conjuntoB:
                    print valorInd, "ya exite en el Conjunto B"
                else:
                    conjuntoB.append(valorInd)
            else:
                print valorInd, "no existe en el Universo."
        print(conjuntoB)
        
    return

def conjuntosAvanzados(): #define una funcion que consigue valores de forma "avanzada"
    print "Ingrese los valores del Conjunto Universal: (Escriba fin en nueva linea al terminar)"
    i=1 
    while 1: #creamos un loop para poder ir ingresando los elementos de los conjuntos
        item=raw_input('Valor %d:' %i)
        if item=='fin': #en el caso de que se escriba 'fin' se hace un break y se sale del loop 
            break
        if item in conjuntoU: #Esta version tambien revisa si hay valores no permitidos, pero iguala valores a los conjuntos como strings y no caracteres
            print valorInd, "ya exite en el Conjunto Universal"
        else:
            conjuntoU.append(item)
            i+=1
        print(conjuntoU)
        
       
    print "Ingrese los valores del Conjunto A:"#loop para ingresar los valores del subconjunto a 
    i=1
    while 1:
        item=raw_input('Valor %d: '%i)
        if item=='fin':
            break
        if item in conjuntoU:
            if item in conjuntoA: #si el string ya existe en el conjunto,
                print item, "ya existe en el Conjunto A" #le dice al usuario
            else: #si no, 
                conjuntoA.append(item) #lo agrega al conjunto y aumenta el contador de valor del conjunto
                i+=1
            print(conjuntoA)
        else: #en el caso de que se ingrese un elemento que no se encuentre dentro del conjunto universo
                #no se asignara el valor ingresado y se notificara
            print item, "no existe en el Universo."
    
    print "Ingrese los valores del Conjunto B:" #Hace lo mismo que las lineas arriba pero para el conjunto B
    i=1
    while 1:
        item=raw_input('Valor %d:' %i)
        if item=='fin':
            break
        if item in conjuntoU:
            if item in conjuntoB:
                print item, "ya existe en el Conjunto B"
            else:
                conjuntoB.append(item)
                i+=1
            print(conjuntoB)
        else:
            print item, "no existe en el Universo."
            
    return

def menu(): # funcion que despliega el menu de opciones para las operaciones que se pueden hacer
    print "Opciones:" 
    print "1. Union"
    print "2. Interseccion"
    print "3. Diferencia"
    print "4. Complemento"
    print "5. Potencia"
    print "6. Ver opciones nuevamente"
    print "0. Salir"
    return

def opciones(): #definicion que imprime los conjuntos y los analiza de acuerdo a las opciones del usuario
    global conjuntoA
    global conjuntoB
    global conjuntoU
    
    print "Conjunto A:", conjuntoA # impresion del conjunto a
    print "Conjunto B:", conjuntoB # impresion del conjunto b
    print "Conjunto Universal:", conjuntoU #impresion del conjunto universal
    menu()
    
    i=0
    while 1: #loop donde se encuentran todas las opciones 
        if i>1:
            accion=input('Que operacion desea hacer? (Recuerde que 6 muestra las opciones)  ')
        else:
            accion=input('Que operacion desea hacer?  ')
        i += 1        
        if accion == 1:# en el caso de que se escoja la opcion uno entonces entrara en este if
            union = [] #se inicializara la lista de union
            union = conjuntoA + conjuntoB #se uniran los dos subconjuntos 
            print list(set(union))#convierte union a conjunto, para que no existan valores repetidos y a lista para ordenarlos.
        elif accion == 2:
            interseccion=[]
            interseccion= set(conjuntoA) & set(conjuntoB)# para poder hacer la interseccion, los conjuntos
            # fueron convertidos a sets para poder hacer la operacion e imprimirlo
            print list(interseccion) #y despues se hizo un cast a lista denuevo al imprimirlo
        elif accion == 3:
            diferencia = []
            diferencia = set(conjuntoA) - set(conjuntoB) #conversion de listas a sets para poder hacer la operacion
            print "La diferencia de A - B", list(diferencia) #conversion e impresion de lista
            diferencia = []
            diferencia = set(conjuntoB) - set(conjuntoA)
            print "La diferencia de B - A", list(diferencia)
        elif accion == 4:
            diferencia = []
            diferencia = set(conjuntoU) - set(conjuntoA)
            print "Conjunto complemento de A", list(diferencia)
            diferencia = set(conjuntoU) - set(conjuntoB)
            print "Conjunto complemento de B", list(diferencia)
        elif accion == 5:
            potencia = [[]]
            for item in conjuntoA:      #para cada valor en el conjunto A, 
                potencia += [x+[item] for x in potencia]    #se agrega al conjunto potencia la union entre los valores que ya existen en el 
                                                            #conjunto potencia y el valor del conjunto A
            print "Potencia del conjunto A", potencia
            potencia = [[]]
            for item in conjuntoB:
                potencia += [x+[item] for x in potencia]
            print "Potencia del conjunto B", potencia
        elif accion == 6:
            menu()
        elif accion == 0: #en el caso de que el usuario ingrese la opcion 6, se saldra del while y terminara el programa
            print "Gracias!\n"
            break #break para terminar el loop
        else: #en el caso de que se ingrese una opcion que no este dentro del menu, se le informara al usuario y terminara el programa
            print "Lo siento,", accion, "no es una opcion valida"
        print "" #salto de linea
    return

def principal(): #funcion principal que hace que todo el codigo se vea ordenado y administra todo
    complejidad = 'nada'
    respuesta = 'string'

    print "Bienvenido, este programa resuelve operaciones con conjuntos." #imprime bienvenida

    while 1:
        while 1:
            conjuntoU[:] = []   #limpia los conjuntos para multiusos sin interferencia de usos anteriores
            conjuntoA[:] = []
            conjuntoB[:] = []
            
            complejidad = raw_input('Quieres el modo express o avanzado?  ') #pregunta forma de conseguir conjuntos
            if ((complejidad == 'express') or (complejidad == 'Express') or (complejidad == 'EXPRESS')): #si quiere express el usuario, 
                conjuntosExpress() #consigue conjuntos de forma express
                opciones() #corre funcion opciones
                break #sale del loop
            elif ((complejidad == 'avanzado') or (complejidad == 'Avanzado') or (complejidad == 'AVANZADO')): #si quiere avanzado el usuario, 
                conjuntosAvanzados() #consigue conjuntos de forma avanzada
                opciones() #corre funcion opciones
                break #sale del loop
            else: #si introduce string que no tiene funcion, 
                print "La opcion", complejidad, "no existe." #le dice que no escribio algo valido y sigue en el loop para preguntar nuevamente
        
        while 1:
            respuesta=raw_input('Desea volver a dar los conjuntos? (si/no)  ') #pregunta si quiere dar nuevos conjuntos
            if ((respuesta == 'si') or (respuesta == 'Si') or (respuesta == 'SI')): #revisa respuesta
                print "" #hace salto de linea
                break #sale del loop
            elif ((respuesta == 'no') or (respuesta == 'No') or (respuesta == 'NO')):#revisa si no quiere otro conjunto
                break #sale del loop
            else:
                print "Lo siento", respuesta, "no es una opcion valida, 'si' o 'no'\n" #si no escribio nada valido, le dice al usuario
        if ((respuesta == 'no') or (respuesta == 'No') or (respuesta == 'NO')): #si la respuesta a poner nuevos conjuntos es no,
            print "Gracias, hasta luego!\n" #da las gracias y 
            break         #termina el loop acabando la funcion principal y terminando el codigo
    return

principal()