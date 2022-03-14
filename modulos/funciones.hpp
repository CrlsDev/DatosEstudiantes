#pragma once
bool pilaMeter(int p[],int &t,int n,int d){
	if(t==n)
		return false;
	p[t++]=d;
	return true;
}
void colaMeter(NODO *&cab,int d){
	NODO *aux=new NODO;
	aux->dato=d;
	aux->sig=NULL;
	if(cab==NULL)
		cab=aux;
	else{
		NODO *ult=cab;
		while(ult->sig!=NULL)
			ult=ult->sig;
		ult->sig=aux;
	}
	void Mostrar(int p[],int t){
	if(t==0)
		cout<<"vacia";
	else
		for(int i=0;i<t;i++)
			cout<<p[i]<<" ";	
}
bool pilaBuscar(int p[],int t,int d){
	for(int i=0;i<t;i++)
		if(d==p[i])
			return true;
	return false;	
}
