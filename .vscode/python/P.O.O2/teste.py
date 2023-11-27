import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QListView
from PyQt5.QtGui import QStandardItemModel, QStandardItem
from tela_lista import Tela_lista

class MinhaApp(QMainWindow):
    def __init__(self):
        super().__init__()

        self.ui = Tela_lista()
        self.ui.setupUi(self)

        lista_view = self.ui.listView

        modelo = QStandardItemModel()
        
        for i in range(1, 51):
            item = QStandardItem(f'DIO {i}')
            modelo.appendRow(item)

        lista_view.setModel(modelo)

def run():
    app = QApplication(sys.argv)
    janela = MinhaApp()
    janela.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    run()
