"""Sistema de controle de usuários da EBAC.

Migração para Python do programa original em C/C++.
Os registros continuam sendo armazenados individualmente pelo CPF,
mas dentro do diretório ``dados`` para manter o projeto organizado.
"""

from pathlib import Path


SENHA_ADMIN = "admin"
DIRETORIO_DADOS = Path(__file__).resolve().parent / "dados"


def normalizar_cpf(cpf: str) -> str:
    """Mantém somente os dígitos informados no CPF."""
    return "".join(caractere for caractere in cpf if caractere.isdigit())


def caminho_registro(cpf: str) -> Path:
    """Retorna o arquivo associado ao CPF informado."""
    return DIRETORIO_DADOS / normalizar_cpf(cpf)


def pausar() -> None:
    input("\nPressione Enter para continuar...")


def registrar() -> None:
    """Cadastra ou atualiza um usuário no sistema."""
    print("### Cadastro de usuário ###\n")

    cpf = normalizar_cpf(input("Digite o CPF a ser cadastrado: ").strip())
    if not cpf:
        print("CPF inválido.")
        pausar()
        return

    nome = input("Digite o nome a ser cadastrado: ").strip()
    sobrenome = input("Digite o sobrenome a ser cadastrado: ").strip()
    cargo = input("Digite o cargo a ser cadastrado: ").strip()

    DIRETORIO_DADOS.mkdir(parents=True, exist_ok=True)
    caminho_registro(cpf).write_text(
        f"{cpf},{nome},{sobrenome},{cargo}", encoding="utf-8"
    )

    print("\nUsuário cadastrado com sucesso!")
    pausar()


def consultar() -> None:
    """Consulta um usuário pelo CPF."""
    print("### Consulta de usuário ###\n")

    cpf = normalizar_cpf(input("Digite o CPF a ser consultado: ").strip())
    arquivo = caminho_registro(cpf)

    if not cpf or not arquivo.exists():
        print("Não foi possível localizar o usuário.")
        pausar()
        return

    conteudo = arquivo.read_text(encoding="utf-8").strip()
    campos = conteudo.split(",", maxsplit=3)

    print("\nEssas são as informações do usuário:")
    if len(campos) == 4:
        cpf_salvo, nome, sobrenome, cargo = campos
        print(f"CPF: {cpf_salvo}")
        print(f"Nome: {nome} {sobrenome}")
        print(f"Cargo: {cargo}")
    else:
        print(conteudo)

    pausar()


def deletar() -> None:
    """Exclui um usuário pelo CPF."""
    print("### Exclusão de usuário ###\n")

    cpf = normalizar_cpf(input("Digite o CPF do usuário a ser deletado: ").strip())
    arquivo = caminho_registro(cpf)

    if not cpf or not arquivo.exists():
        print("O usuário não se encontra no sistema.")
        pausar()
        return

    arquivo.unlink()
    print("Usuário deletado com sucesso!")
    pausar()


def menu() -> None:
    """Exibe o menu principal até o usuário escolher sair."""
    while True:
        print("\n### Controle da EBAC ###\n")
        print("Escolha a opção desejada do menu:\n")
        print("\t1 - Registrar nomes")
        print("\t2 - Consultar nomes")
        print("\t3 - Deletar nomes")
        print("\t4 - Sair do sistema\n")

        opcao = input("Opção: ").strip()

        if opcao == "1":
            registrar()
        elif opcao == "2":
            consultar()
        elif opcao == "3":
            deletar()
        elif opcao == "4":
            print("Obrigado por utilizar o sistema!")
            return
        else:
            print("Essa opção não está disponível!")
            pausar()


def main() -> None:
    print("### Controle da EBAC ###\n")
    print("Login de administrador!\n")
    senha = input("Digite a sua senha: ")

    if senha != SENHA_ADMIN:
        print("Senha errada!")
        return

    menu()


if __name__ == "__main__":
    main()
