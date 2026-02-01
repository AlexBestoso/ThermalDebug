// NOTE: We may want to use static_cast<type>(this->value) to handle returning values.
class ThermalVariable{
	private:
		std::string name;
		std::string dataType;
		void *value;
	public:

		ThermalVariable(){
			this->name = "";
			this->dataType = "";
			this->value = NULL;
		}

		void create(std::string t, std::string n, void *v){
			this->name = n;
			this->value = v;
			this->dataType = t;
		}

		std::string getName(void){
			return this->name;
		}
		std::string getDataType(void){
			return this->dataType;
		}
		void *getValue(void){
			return this->value;
		}
	
};
