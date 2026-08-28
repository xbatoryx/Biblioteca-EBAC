# Biblioteca-EBAC

Projeto do curso de TI da EBAC, migrado de C/C++ para **Python 3**.

## Funcionalidades

- Login de administrador
- Cadastro de usuários por CPF
- Consulta de usuários por CPF
- Exclusão de usuários por CPF
- Persistência local dos registros no diretório `dados/`

## Requisitos

- Python 3.9 ou superior

O projeto utiliza somente a biblioteca padrão do Python, portanto não é necessário instalar dependências externas.

## Como executar

No terminal, dentro da pasta do projeto:

```bash
python biblioteca.py
```

Em alguns sistemas, o comando pode ser:

```bash
python3 biblioteca.py
```

A senha administrativa mantida do projeto original é:

```text
admin
```

## Estrutura

```text
Biblioteca-EBAC/
├── biblioteca.py
├── dados/            # criado automaticamente ao cadastrar o primeiro usuário
└── README.md
```

## Migração

A implementação original estava no arquivo `biblioteca12.cpp`. A versão Python mantém as funcionalidades centrais do projeto, substituindo operações específicas do Windows (`system("cls")` e `system("pause")`) por código portátil em Python e organizando os registros dentro da pasta `dados`.
