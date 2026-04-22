**_Proyecto SIGLOR: Propuesta inicial para la definición de nodos y rutas_**

_Lautaro Bravo 22/04/2026_

El presente documento forma parte de la etapa de investigación y planificación del proyecto final correspondiente a la materia Estructura de Datos y Algoritmos II.

Como primer paso concreto hacia la construcción del sistema, este documento presenta la propuesta de definición de los nodos (ciudades) y las rutas (conexiones) que conformarán el grafo base sobre el cual operará la aplicación. La selección de los nodos se realizó tomando como referencia la provincia de Buenos Aires, priorizando localidades con relevancia logística real, conectividad vial documentada y una distribución geográfica que permita demostrar el funcionamiento del algoritmo de camino más corto ante distintos escenarios.

La red propuesta está compuesta por cinco nodos principales; La Plata, Mar del Plata, Tandil, Olavarría y Bahía Blanca, interconectados mediante ocho rutas basadas en distancias reales expresadas en kilómetros, obtenidas a partir de las rutas nacionales y provinciales que los vinculan.

Las secciones siguientes detallan las características de cada nodo, las conexiones definidas con sus respectivas distancias, y las coordenadas geográficas asociadas a cada ciudad para su representación gráfica dentro de la interfaz de la aplicación.

**_Nodos_**

_Nodos principales_:

La consigna del proyecto nos pide mínimamente 3 nodos. Los siguientes fueron elegidos debido a su importancia logística y su cantidad de conexiones (rutas) posibles con demás nodos.

**La Plata**: Capital de la provincia, centro administrativo y de distribución. Coordenadas:

- Latitud: -34.92
- Longitud: -57.95

**Mar del Plata**: Ciudad más populosa del interior provincial, puerto pesquero activo y gran movimiento comercial.

Coordenadas:

- Latitud: -37.99
- Longitud: -57.55

**Bahía Blanca**: Principal puerto del sur bonaerense, hub de exportación de granos y petroquímica. Nodo clave en logística de larga distancia.

Coordenadas:

- Latitud: -36.71
- Longitud: -62.27

_Nodos secundarios:_

Estos nodos secundarios servirán para proporcionar la conectividad necesaria entre los nodos principales.

**Tandil**: Nodo serrano, industria metalmecánica.

Coordenadas:

- Latitud: -37.33
- Longitud: -59.15

**Olavarría**: Industria cementera, punto medio sur.

Coordenadas:

- Latitud: -36.89
- Longitud: -60.32

![Ver nodos](./assets/nodos.png)

**_Conexiones_**

**La Plata - Mar del Plata**

La Plata conexión a Mar del Plata mediante RN2, 370km.

**La Plata - Tandil**

La Plata conexión a Tandil mediante RP215 hasta km38 (Cnel. Brandsen), luego RP29 hasta km282 (Ayacucho) y la RP74 hasta km333, y un último corto tramo hasta Tandil para un total de 347km.

**La Plata - Olavarría**

La Plata conexión a Olavarria mediante RP215 hasta km100 (San Miguel de Monte), luego RN3 hasta km300 (Azul), donde se toma la RN226 hasta Olavarría, 345km.

**La Plata - Bahía Blanca**

La Plata conexión a Bahía Blanca mediante RP215 hasta km99 (San Miguel de Monte), donde se tomará la RN3 hasta km296 (Azul), seguida de la RP51 hasta Bahía Blanca, 627km.

**Tandil - Mar del Plata**

Tandil conexión a Mar del Plata mediante RN226 directo hasta Mar del Plata, 171km.

**Tandil - Olavarría**

Tandil conexión a Olavarría mediante RN226 directo hasta Olavarría, 135km.

**Tandil - Bahía Blanca**

Tandil conexión a Bahía Blanca mediante RP74 hasta km85 y luego RN3 hasta Bahía Blanca, 370km.

**Mar del Plata - Bahía Blanca**

Mar del Plata conexión a Bahía Blanca mediante RP88 hasta km124 (Necochea), luego RN228 hasta km271 (Tres Arroyos) y luego RN3 hasta Bahía Blanca,

**Olavarría - Bahía Blanca**

Olavarría conexión a Bahía Blanca mediante RP51 directo hasta Bahía Blanca, 298km.

**Olavarría - Mar del Plata**

Olavarría conexión a Mar del Plata mediante RN226 directo hasta Mar del Plata, 305km.

![Ver rutas](./assets/rutas.png)

Si bien se especifican las rutas que toma cada camino y las localidades intermedias, esto es más que nada para entender y visualizar mejor los caminos existentes. A la hora de realizar los cálculos para decidir el camino más corto, se tomará todo el conjunto de rutas que constituye el camino como una sola línea, y no se tendrán en cuenta las localidades intermedias ni se les tratará como nodos individuales.

![Ver grafo](./assets/grafo.png)

A continuación se resumirá la información necesaria de este documento en tablas para hacer su posterior utilización más rápida.

**_Coordenadas_**

| **Ciudades**    | **Latitud** | **Longitud** |
| --------------- | ----------- | ------------ |
| _La Plata_      | \-34.92     | \-57.95      |
| _Mar del Plata_ | \-37.99     | \-57.55      |
| _Bahía Blanca_  | \-36.71     | \-62.27      |
| _Tandil_        | \-36.89     | \-60.32      |
| _Olavarría_     | \-37.33     | \-59.15      |

**_Matriz de adyacencia_**

|       | **1** | **2** | **3** | **4** | **5** |
| ----- | ----- | ----- | ----- | ----- | ----- |
| **1** | 0     | 370   | ∞     | 345   | 347   |
| **2** | 370   | 0     | 465   | ∞     | 171   |
| **3** | ∞     | 465   | 0     | 298   | 370   |
| **4** | 345   | ∞     | 298   | 0     | 135   |
| **5** | 347   | 171   | 370   | 135   | 0     |
