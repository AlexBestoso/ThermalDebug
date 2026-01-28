class ThermalOperation{
	private:
		struct thermalOperation data;	
	public:
		void init(void){
			this->data.name = "";
			this->data.description = "";
			this->data.inputCount = 0;
			this->data.inputs = NULL;
			this->data.outputCount = 0;
			this->data.outputs = NULL;

		}
		void reset(void){

		}
		ThermalOperation(){

		}

		~ThermalOperation(){

		}
};
