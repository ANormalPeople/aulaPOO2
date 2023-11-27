import pyautogui
import keyboard
import threading

def acao_mouse():
    while not encerrar:
        pyautogui.click(interval=0.25, button='left')

def controle_clique():
    global encerrar
    thread_mouse = threading.Thread(target=acao_mouse)
    while True:
        event = keyboard.read_event()
        if event.event_type == keyboard.KEY_DOWN:
            if event.name == 'q' and  thread_mouse.is_alive():
                encerrar = True
                thread_mouse.join()
                
            if event.name == 'e':
                if not thread_mouse.is_alive():
                    encerrar = False
                    thread_mouse = threading.Thread(target=acao_mouse)
                    thread_mouse.start()
                    
            if event.name == 'esc':
                encerrar = True
                if thread_mouse.is_alive():
                    thread_mouse.join()
                break
            
encerrar = False
print("e-iniciar")
print("q-encerrar")
print("esc-sair")

thread_controle = threading.Thread(target=controle_clique)
thread_controle.start()
thread_controle.join()