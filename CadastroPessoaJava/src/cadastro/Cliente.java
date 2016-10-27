/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cadastro;

/**
 *
 * @author Cleber
 */
public class Cliente extends Pessoa {
    private String  codigo;

    public Cliente(String nome, int idade, float altura, float peso, char sexo, String codigo) {
        super(nome, idade, altura, peso, sexo);
        setCodigo(codigo);
    }
     public void setCodigo(String codigo){
         if (codigo.length() < 6)
             throw new IllegalArgumentException ();
         else
             this.codigo = codigo;
     }
     
     public String getCodigo(){
         return codigo;
     }
    
}
