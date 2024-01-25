# Sistema de Seguridad Vehicular

Este proyecto implementa un sistema de seguridad para vehículos que incluye la lectura continua de la velocidad del vehículo, detección de umbrales de seguridad y acciones de emergencia, así como la comunicación con una Raspberry Pi a través de MQTT.

## Descripción del Sistema

El sistema consta de los siguientes componentes:

1. **Pulsador para Iniciar el Sistema:**
   - El sistema se activa mediante un pulsador.
   - Una vez activado, el display LCD mostrará "SYSTEM ON".
   - Permanecerá activo indefinidamente mientras la EK esté alimentada.

2. **Lectura Continua de Velocidad:**
   - La velocidad se emula mediante la lectura de un potenciómetro conectado al módulo ADC.
   - Se utiliza un filtro de mediana móvil para evitar valores atípicos.

3. **Comunicación con Raspberry Pi:**
   - Todos los valores filtrados se envían a la Raspberry Pi por UART.
   - La Raspberry Pi guarda las lecturas en un log (csv o txt) con timestamp.

4. **Freno de Emergencia:**
   - Se activa cuando la velocidad supera el 75% de la velocidad máxima.
   - Comando de freno: parpadeo del LED y mensaje de "PELIGRO" en el display LCD.
   - Emisión de un zumbador durante 1 segundo.

5. **Comunicación MQTT:**
   - La Raspberry Pi publica un mensaje en un broker MQTT cuando se activa el freno de emergencia.
   - El mensaje contiene la velocidad actual y un timestamp.

6. **Restauración del Sistema:**
   - Cuando la velocidad baja del umbral de emergencia, se restaura el display LCD y el LED.

7. **Cliente MQTT en Ordenador Portátil:**
   - Se ejecuta un cliente MQTT (suscriptor) en un ordenador portátil.
   - El cliente está suscrito al topic correspondiente y muestra mensajes en la terminal.

## Configuración y Uso

1. **Requisitos de Hardware:**
   - Kit de desarrollo de Renesas EK-RA4M1.
   - Raspberry Bi.
     
2. **Tecnologías utilizadas:**
   - I2C, UART, ADC, MQTT, ARM-Cortex, Python, C
     
2. **Configuración de la Raspberry Pi y MQTT Broker:**
   - Asegúrate de que la Raspberry Pi esté conectada a la red, ya sea mediante Ethernet o Wi-Fi.
   - Acceder a la Raspberry Pi a través de SSH.
   - Instala el broker MQTT Mosquitto con el siguiente comando: sudo apt install mosquitto.
   - Verifica si el servicio de Mosquitto está en ejecución: sudo systemctl status mosquitto.
   - Configuramos la autenticación y los permisos de acceso para Mosquitto editando el archivo de configuración: sudo nano /etc/mosquitto/mosquitto.conf.
   - Reinicia el servicio Mosquitto después de realizar cambios en la configuración: sudo systemctl restart mosquitto.
   - En el código e2studio, hay que fijarse de que la configuración de MQTT apunte al servidor Mosquitto en la dirección IP de la Raspberry Pi y al puerto correcto.
   - Utilizamos las herramientas como mosquitto_pub y mosquitto_sub para realizar pruebas de publicación y suscripción desde la Raspberry Pi y otros dispositivos.
   - Utilizamos las herramientas como mqtt-spy o MQTT Explorer para monitorear el tráfico MQTT y verificar que los mensajes se publiquen correctamente.

3. **Ejecución del Cliente MQTT en el Ordenador Portátil:**
   - Instalar el cliente MQTT en el ordenador portátil.
   - Ejecutamos el cliente MQTT en el ordenador portátil y configuramos la conexión al broker MQTT: mosquitto_sub -h <dirección_IP_broker> -t <topic>
   - Una vez suscrito, el cliente estará escuchando los mensajes publicados en ese tema. Cualquier mensaje publicado en el broker Mosquitto en el mismo tema se mostrará en la terminal del cliente MQTT.
   - Verificamos que los mensajes publicados desde el sistema embebido (freno de emergencia, velocidad, etc.) se están recibiendo correctamente en el cliente MQTT en el ordenador portátil.
   - Deja el cliente MQTT en ejecución para monitorear continuamente los mensajes MQTT.

## Enlaces de Interés

- [Documentación del microcontrolador](https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra4m1-evaluation-kit-ra4m1-mcu-group)
- [Bibliotecas MQTT](https://forums.raspberrypi.com/viewtopic.php?t=199586)
- [Instalación de Mosquitto en la Raspberry Pi](https://www.youtube.com/watch?v=4lT5Gd3kUQw)
