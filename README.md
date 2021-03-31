# GameBoy Twitch - Un emulador desarrollado totalmente en vivo desde Twitch

## ES
En este repositorio encontraréis el avance del emulador de Gameboy que desarrollamos en mi [canal de Twitch](https://twitch.tv/AbdeCreativeDev).

### Requisitos:

- GCC
- GNU Make


### Uso

Podéis compilarlo con el Makefile (en el directorio):

```
make
```

Para ejecutarlo, el makefile os generará un archivo ``gbt`` (Linux) o ``gbt.exe`` (Windows) que deberéis ejecutar así:

Linux:
```
./gbt ROM_NAME
```

Windows:
```
./gbt.exe ROM_NAME
```

donde ``ROM_NAME`` es el nombre de vuestra rom. 

### Recursos

Este emulador está basado en estos recursos (lista no exhaustiva): 

- [GB CPU Manual](http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf)
- [GB Pandocs](https://gbdev.io/pandocs/)
- [Gameboy Talks](https://www.retroreversing.com/gameboy/hardware)
- [GGB - A Game Boy emulator written in C++](https://github.com/geaz/emu-gameboy) -> hemos generado las instrucciones de los opcodes gracias a este proyecto
- [Imran Nazar: Gameboy Emulation in JavaScript](http://imrannazar.com/GameBoy-Emulation-in-JavaScript)
- [The Ultimate GameBoy talk (33c3)](https://www.youtube.com/watch?v=HyzD8pNlpwI)
- [The Game Boy: a hardware architecture](https://www.youtube.com/watch?v=RZUDEaLa5Nw)
- [Memory mapping](http://gameboy.mongenel.com/dmg/asmmemmap.html)

******

## EN
In this repository you will find the progress done on the Gameboy emulator that I am developing live on my [Twitch channel](https://twitch.tv/AbdeCreativeDev).

### Requirements:

- GCC
- GNU Make


### Usage

You can compile the emulator with our Makefile with the command:

```
make
```

To execute it, the make command will generate a file ``gbt`` (Linux) or ``gbt.exe`` (Windows) that you may execute like this:

Linux:
```
./gbt ROM_NAME
```

Windows:
```
./gbt.exe ROM_NAME
```

where ``ROM_NAME`` is the name of our rom.

### Recursos

This emulator is based on the following resources (list is not exhaustive): 

- [GB CPU Manual](http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf)
- [GB Pandocs](https://gbdev.io/pandocs/)
- [Gameboy Talks](https://www.retroreversing.com/gameboy/hardware)
- [GGB - A Game Boy emulator written in C++](https://github.com/geaz/emu-gameboy) -> we have generated the instruction set from the opcode table thanks to this project
- [Imran Nazar: Gameboy Emulation in JavaScript](http://imrannazar.com/GameBoy-Emulation-in-JavaScript)
- [The Ultimate GameBoy talk (33c3)](https://www.youtube.com/watch?v=HyzD8pNlpwI)
- [The Game Boy: a hardware architecture](https://www.youtube.com/watch?v=RZUDEaLa5Nw)
- [Memory mapping](http://gameboy.mongenel.com/dmg/asmmemmap.html)
