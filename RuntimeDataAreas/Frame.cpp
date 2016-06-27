#include "Frame.hpp"
//Construtor para métodos não estáticos
Frame::Frame(Objeto *objeto, string nomeMetodo, string descritorMetodo){
{

   /* for (int i = 0; i < arguments.size(); i++) {
        variaveisLocais[i] = argumentos[i];
    }*/

    pc = 0;

    const method_info *metodoAux = objeto->javaClass->getMetodo(nomeMetodo, descritorMetodo);
    assert(metodoAux != NULL);

    if(objeto->instancia != NULL){
        assert((metodoAux->getAccessFlags() & 0x0008) == 0); // o método não pode ser estático
        }
    else{
        assert((metodoAux->getAccessFlags() & 0x0008) != 0); // o método precisa ser estático
    }

    pegarAtributos();
}

void Frame::pegarAtributos() {
    vector<cp_info*> constantPool = objeto->javaClass.getConstantPool();

    codeAttribute = NULL;
    exceptionsAttribute = NULL;

    for (int i = 0; i < _method.attributes_count; i++) {

        attribute_info *attribute_aux = &(method.attributes[i]);
        CONSTANT_Utf8_info *attributeName = (CONSTANT_Utf8_info*)(constantPool[attribute_aux->GetAttributeNameIndex()-1]);

        if ((*attributeName) == "Code") {

            codeAttribute = &(attributeAux->info.code_info);

            if (exceptionsAttribute != NULL) break;

        }

        else if (attrName == "Exceptions")) {

            exceptionsAttribute = &(attribute_aux->info.exceptions_info);

            if (codeAttribute != NULL) break;
        }
    }
}

Valor Frame::getValorVariavelLocal(uint32_t indice) {

    if (indice >= codeAttribute->max_locals) {

        cerr <<"Tentativa de acesso a variavel local inexistente" << endl;
        exit(1);

    }

    return variaveisLocais[indice];
}

void Frame::mudarVariavelLocal(Valor valorDaVariavel, uint32_t indice) {

    if (indice >= _codeAttribute->max_locals) {

        cerr << "Tentativa de alteração de variavel local inexistente" << endl;
        exit(1);

    }

    variaveisLocais[indice] = valorDaVariavel;

}

void Frame::empilharOperando(Valor operando) {

    pilhaOperandos.push(operando);

}

Valor Frame::desempilhaOperando() {

    if (pilhaOperandos.size() == 0) {

        cerr << "IndexOutOfBoundsException" << endl;
        exit(1);

    }

    Valor topo = pilhaOperandos.top();

    pilhaOperandos.pop();

    return top;
}

stack<Valor> Frame::retornaPilhaOperandos(){}

    return pilhaOperandos;

}


void Frame::setaPilhaOperandos(stack<Valor> pilha){

    pilhaOperandos = pilha;

}

uint8_t Frame::getCode() {

    return codeAttribute->code + pc;

}

uint16_t Frame::tamanhoVetorVariaveis() {

	return codeAttribute->max_locals;

}

uint32_t Frame::tamanhoCode() {

	return codeAttribute->code_length;

}

void Frame::incrementaPC(){
    pc = pc + 1;
}
