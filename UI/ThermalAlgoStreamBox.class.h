class ThermalAlgoStreamBox : public ThermalBox{
	private:
		ThermalBox builderBox;
		thermbox_t *_data;

		int displayW;
		int displayH;
	public:

	ThermalAlgoStreamBox(){
		this->displayW = 0;
		this->displayH = 0;
		
		this->_data = this->getData();
		if(this->_data == NULL) return;
		this->_data->corner_top_left = THERMAL_BOXLINE_CORNER_TL_LIGHT;
		this->_data->corner_top_right = THERMAL_BOXLINE_CORNER_TR_LIGHT;
		this->_data->corner_bottom_left = THERMAL_BOXLINE_CORNER_BL_LIGHT;
		this->_data->corner_bottom_right = THERMAL_BOXLINE_CORNER_BR_LIGHT;
		this->_data->edge_top = THERMAL_BOXLINE_HOR_LIGHT;
		this->_data->edge_bottom = THERMAL_BOXLINE_HOR_LIGHT;
		this->_data->edge_left = THERMAL_BOXLINE_VER_LIGHT;
		this->_data->edge_right = THERMAL_BOXLINE_VER_LIGHT;
		this->_data->fill = THERMAL_BOXELEMENT_EMPTY;

		this->_data->width = 0;
		this->_data->height = 0;
		this->_data->data_size = 0;
		this->_data->data = NULL;

		this->_data = this->builderBox.getData();
		if(this->_data == NULL) return;
		this->_data->corner_top_left = THERMAL_BOXLINE_CORNER_TL_LIGHT;
		this->_data->corner_top_right = THERMAL_BOXLINE_CORNER_TR_LIGHT;
		this->_data->corner_bottom_left = THERMAL_BOXLINE_CORNER_BL_LIGHT;
		this->_data->corner_bottom_right = THERMAL_BOXLINE_CORNER_BR_LIGHT;
		this->_data->edge_top = THERMAL_BOXLINE_HOR_LIGHT;
		this->_data->edge_bottom = THERMAL_BOXLINE_HOR_LIGHT;
		this->_data->edge_left = THERMAL_BOXLINE_VER_LIGHT;
		this->_data->edge_right = THERMAL_BOXLINE_VER_LIGHT;
		this->_data->fill = THERMAL_BOXELEMENT_EMPTY;

		this->_data->width = 0;
		this->_data->height = 0;
		this->_data->data_size = 0;
		this->_data->data = NULL;



		ThermalBox();

	}

	~ThermalAlgoStreamBox(){

	}

	// TODO: displayHeight is deprecated.
	bool setArea(int displayWidth, int displayHeight){
		this->displayW = displayWidth;
		this->displayH = displayHeight;
		this->_data = this->getData();
		
		// Unallocated!
		if(this->_data == NULL) return false;

		// Use screen dimentions to calculate box sizes.
		if(!this->setBoxArea(displayW-2, 8)) return false; // <-- TODO: make configurable
		if(!this->builderBox.setBoxArea(17, 5)) return false;
		
		return true;	
	}

	bool mapAlgorithmName(int x, int y, std::string name){
		return this->builderBox.mapString(x, y, name);
	}

	bool buildBox(void){
		if(!this->generateBoxData()){
			return false;
		}

		if(!this->builderBox.generateBoxData()){
			return false;
		}
		
		int wA = this->displayW / 2;
		int wB = 17/2;
		int centerOffset = wA - wB;
		if(centerOffset < 0) centerOffset *= -1;

		/*
			TODO: Development continues here.
				Main goals: 
					- Fix resize bug, 
					- figure out why fuseByEdge is failing.
		*/

		if(!this->fuseByEdge(this->builderBox, THERMAL_BOXEDGE_TOP, centerOffset)){
			return false; // and one day, an error too.
		}
		
		return true;
	}

};
