import sys

from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMainWindow, QApplication, QMessageBox

from tela_inicial import Tela_Inicial
from tela_buscar import Tela_Buscar
from tela_cadastro import Tela_Cadastro 
from pessoa import Pessoa
from cadastro import Cadastro

class Ui_Main(QtWidgets.QWidget):
    def setupUi(self, Main):
        Main.setObjectName('Main')
        Main.resize(640, 480)

        self.QtStack = QtWidgets.QStackedLayout()

        self.stack0 = QtWidgets.QMainWindow()
        self.stack1 = QtWidgets.QMainWindow()
        self.stack2 = QtWidgets.QMainWindow()
   
        self.tela_inicial = Tela_Inicial()
        self.tela_inicial.setupUi(self.stack0)

        self.tela_cadastro = Tela_Cadastro()
        self.tela_cadastro.setupUi(self.stack1)

        self.tela_buscar = Tela_Buscar()
        self.tela_buscar.setupUi(self.stack2)

        self.QtStack.addWidget(self.stack0)
        self.QtStack.addWidget(self.stack1)
        self.QtStack.addWidget(self.stack2)


class Main(QMainWindow, Ui_Main):
    def __init__(self):
        super(Main, self).__init__(None)
        self.setupUi(self)

        self.cad = Cadastro()
        self.tela_inicial.pushButton.clicked.connect(self.abrirTelaCadastro) # funções dos botões da tela principal
        self.tela_inicial.pushButton_2.clicked.connect(self.abrirTelaBuscar)
        self.tela_inicial.pushButton_3.clicked.connect(self.sair)

        self.tela_cadastro.pushButton.clicked.connect(self.botaoCadastra)
        self.tela_cadastro.pushButton_2.clicked.connect(self.botaoVoltar)
        self.tela_buscar.pushButton_dio.clicked.connect(self.botaoVoltar)
        self.tela_buscar.pushButton_2.clicked.connect(self.botaoBusca)

    def botaoCadastra(self):
        nome = self.tela_cadastro.lineEdit.text()
        endereco = self.tela_cadastro.lineEdit_2.text()
        cpf = self.tela_cadastro.lineEdit_3.text()
        nascimento = self.tela_cadastro.lineEdit_4.text()
        if not(nome == '' or endereco == '' or cpf == '' or nascimento == ''):
            p = Pessoa(nome,endereco,cpf,nascimento)
            if (self.cad.cadastra(p)):
                QMessageBox.information(None,'POOII', 'Cadastro realizado com sucesso!')
                self.tela_cadastro.lineEdit.setText('')
                self.tela_cadastro.lineEdit_2.setText('')
                self.tela_cadastro.lineEdit_3.setText('')
                self.tela_cadastro.lineEdit_4.setText('')
            else:
                QMessageBox.information(None,'POOII', 'O CPF informado já está cadastrado na base de dados!')
        else:
            QMessageBox.information(None,'POOII', 'Todos os valores devem ser preenchidos!')

        self.QtStack.setCurrentIndex(0)

    def botaoBusca(self):
        cpf = self.tela_buscar.lineEdit_5.text()
        pessoa = self.cad.busca_servico(cpf)
        print(pessoa)
        
        if (pessoa!=None):
            self.tela_buscar.lineEdit_7.setText(str(pessoa[0][0]))
            self.tela_buscar.lineEdit_6.setText(pessoa[0][1])
            self.tela_buscar.lineEdit_8.setText(pessoa[0][2])
        else:
            QMessageBox.information(None,'POOII', 'CPF não encontrado!')
            
    def botaoVoltar(self):
        self.QtStack.setCurrentIndex(0)
        
    def abrirTelaCadastro(self):
        self.QtStack.setCurrentIndex(1)

    def abrirTelaBuscar(self): 
        self.QtStack.setCurrentIndex(2)
        
    def sair(self):
        app.quit()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    show_main = Main()
    sys.exit(app.exec_())
