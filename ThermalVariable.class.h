
class ThermalVariable{
	private:
		std::string name;
		std::string value;
		int dataType;
	public:
	
		int dataTypeByName(std::string type){
			if(type == "float"){return 0;}
			if(type == "signed float"){return 1;}
			if(type == "unsigned float"){return 2;}
			if(type == "double"){return 3;}
			if(type == "signed double"){return 4;}
			if(type == "unsigned double"){return 5;}
			if(type == "int"){return 6;}
			if(type == "char"){return 7;}
			if(type == "signed char"){return 8;}
			if(type == "unsigned char"){return 9;}
			if(type == "signed int"){return 10;}
			if(type == "unsigned int"){return 11;}
			
			return -1;
		}

		std::string dataTypeById(int id){
			switch(id){
				case 0:
					return "float";
				case 1:
					return "signed float";
				case 2:
					return "unsigned float";
				case 3:
					return "double";
				case 4:
					return "signed double";
				case 5:
					return "unsigned double";
				case 6:
					return "int";
				case 7:
					return "char";
				case 8:
					return "signed char";
				case 9:
					return "unsigned char";
				case 10:
					return "signed int";
				case 11:
					return "unsigned int";
			}
			return "";
		}
	
};
