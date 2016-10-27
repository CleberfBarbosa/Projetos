/*
 * 
Private: A única classe que tem acesso ao atributo é a própria classe que o define, ou seja, se uma classe Pessoa declara um atributo privado chamado nome, somente a classe Pessoa terá acesso a ele.

Default: Tem acesso a um atributo default (identificado pela ausência de modificadores) todas as classes que estiverem no mesmo pacote que a classe que possui o atributo.

Protected: Ele é praticamente igual ao default, com a diferença de que se uma classe (mesmo que esteja fora do pacote) estende da classe com o atributo protected, ela terá acesso a ele. Então o acesso é por pacote e por herança.

Public: Todos tem acesso 
 */
package cadastro;

import java.util.Scanner;

/**
 *
 * @author Cleber
 */
public class Cadastro {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        boolean valida=true;
        Scanner scan;
        scan = new Scanner(System.in);
        
        Cliente cliente;
        
        String nome;
        int idade;
        float altura, peso;
        char sexo;
        
            
        
        do{
            valida = true;
            System.out.println("Digite o Nome: ");
            nome = scan.next();
            if(nome.length()<6 || nome.length() > 100){
                System.out.println("O nome deve ser maior ou igual a 6 e menor ou igual a 100 caracteres.");
                valida= false;
            }
        }while(!valida);
        
        do{
            valida = true;
            System.out.println("Digite a idade: ");
            idade = scan.nextInt();
            if(idade < 0 || idade > 100){
                System.out.println("Idade dever >= 0 e <= 100.");
                valida= false;
            }
        }while(!valida);
        
        do{
            valida = true;
            System.out.println("Digite a altura: ");
            altura = scan.nextFloat();
            if(altura < 0.1){
                System.out.println("A altura nao pode ser 0 ou negativa.");
                valida= false;
            }
        }while(!valida); 
        
        do{
            valida = true;
            System.out.println("Digite o peso: ");
            peso = scan.nextFloat();
            if(peso < 0.1){
                System.out.println("O peso nao pode ser 0 ou negativo.");
                valida= false;
            }
        }while(!valida);
        
        do{
            valida =true;
            System.out.println("Digite o sexo (m/f): ");
            sexo = scan.next().toUpperCase().charAt(0);
            if(sexo!='M' && sexo!='F'){
                System.out.println("Sexo invalido, entre com M ou F.");
                valida= false;
            }
        }while(!valida);
            
            try{
                
                cliente = new Cliente(nome, idade, altura, peso, sexo, "123456" );
                Pessoa pessoa = cliente;
                System.out.println("Nome: " + cliente.getNome());
                System.out.println("Idade: " + cliente.getIdade());
                System.out.println("Altura: " + cliente.getAltura());
                System.out.println("Peso: " + cliente.getPeso());
                System.out.println("Sexo: " + cliente.getSexo());
                System.out.println("Codigo: " + cliente.getCodigo());
                System.out.println("Sessão finalizada corretamente.");
            }catch(IllegalArgumentException e){
                System.out.println("ERRO NA ENTRADA.");
            }
        
        }
    }
    

