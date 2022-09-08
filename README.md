# Documentación de Become iOS SDK

Proceso de instalación de la librería become_IOS_SDK.

## Agregar Alamofire al proyecto
Se debe agregar la librería **Alamofire** al proyecto, click [aqui](https://github.com/Alamofire/Alamofire) para la documentación. 


## Agregar Frameworks al proyecto
Se debe agregar la librería `BecomeDigitalV.framework` en las configuraciones generales del proyecto en la sección **framework, libraries, and embedded content**:

Para el correcto funcionamiento de la SDK, se requiere el uso de los frameworks o librerías `Alamofire.framework` y `Microblink.xcframework`, los cuales se deben adicionar en la sección **framework, libraries, and embedded content**:
 
 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK_Document_Authentication/blob/main/IMG_2.png">
</p>

## Configuraciones dentro de info.plist 

La SDK requiere que dentro de las configuraciones `info.plis`, se encuentre una descripción de uso de la cámara:

    Privacy - Camera Usage Description ( Esta aplicación hace uso de tu cámara)
    
 <p align="center">
  <img src="https://github.com/Becomedigital/become_IOS_SDK/blob/master/IMG_3.png">
 </p>
 
## Inicialización de la SDK

**1. Importar el SDK en nuestro viewController:**

        import  BecomeDigitalV


**2. En el método `startSDKAction ()` de su `ViewController` de aplicación, inicialice Become para la captura de imágenes, se debe asignar el `ItFirstTransaction` como True, puedes utilizar el siguiente fragmento de código:**
 
      @IBAction func startSDKAction(_ sender: Any) {
               let dateFormatter = DateFormatter()
               dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
               dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
               userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
               
               let bdivConfig = BDIVConfig(token: "your_bearer_token",
                                        contractId: "your_contract_id",
                                        userId: userID,
                                        customLocalizationFileName:  "localize_test")
                                              
               BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
       }
                    

 ## Cambiar textos predeterminados en la SDK     

Para cambiar algún texto predeterminado y asignar uno en reemplazo de este, cree un archivo .string ejemplo: `localize_test.strings` en su proyecto y agrege la eqtiqueta del texto a remplazar ejemplo: `"blinkid_generic_message" = "Su texto aca";`, luego agregue el atributo `customLocalizationFileName` con el nombre del archivo strings en el objeto `BDIVConfig`.

Con `Localize_test.string.string` abierto, en el inspector de archivos toque el botón "Localizar..." y seleccione Inglés.

    @IBAction func startSDKAction(_ sender: Any) {
             let dateFormatter = DateFormatter()
             dateFormatter.locale = Locale(identifier: "es_ES") // date user identification
             dateFormatter.dateFormat = "yyyyMMddHHmmssSSS"
             userID = userId.text!.isEmpty ? dateFormatter.string(from: Date()) : userId.text!
             let bdivConfig = BDIVConfig(token:"your_bearer_token",
                               contractId:  "your_contract_id",
                               userId: userID,
                               customLocalizationFileName: "localize_test")
             BDIVCallBack.sharedInstance.register(bdivConfig: bdivConfig)
     }
     
**Listado de llaves**

    "blinkid_generic_message" = "Escaneo de la parte frontal\nde un documento";
    "mb_blinkid_back_instructions_barcode" = "Escanea el código de barras";
    "mb_blinkid_camera_flip_document" = "Dele la vuelta al documento";
    "mb_blinkid_camera_high" = "Acercarse";
    "mb_blinkid_camera_near" = "Alejarse";
    "mb_blinkid_document_too_close_to_edge" = "Mueva el documento desde el borde";
    "mb_check_internet_connection" = "Verifique su conexión a Internet";
    "mb_close" = "Cerrar";
    "mb_data_not_match_msg" = "Por favor, inicie el proceso de escaneo de nuevo.";
    "mb_data_not_match_retry_button" = "Reintentar";
    "mb_data_not_match_title" = "Los lados no coinciden";
    "mb_error_mandatory_field_missing" = "Mantenga el documento visible en su totalidad";
    "mb_flashlight_glare_tooltip" = "Tenga cuidado con el resplandor de la linterna.\nMueva suavemente su ID a su alrededor para evitarlo.";
    "mb_network_error" = "Error de red";
    "mb_recognition_timeout_dialog_message" = "No se puede leer el documento. Por favor, inténtelo de nuevo.";
    "mb_recognition_timeout_dialog_title" = "Escaneo fallido";
    "mb_scanning_not_available" = "Escaneo no disponible";
    "mb_something_went_wrong" = "Algo ha ido mal";
    "mb_tooltip_glare" = "Mueva ligeramente la identificación para eliminar el deslumbramiento.";
    "mb_try_scanning_again" = "Parece que la información del documento no es consistente. Intente escanear de nuevo.";
    "mb_unsupported_document_message" = "Escanee la parte frontal de un documento compatible.";
    "mb_unsupported_document_title" = "Documento no reconocido";
    "photopay_align_message" = "Ponga el teléfono sobre el comprobante de pago";
    "photopay_back_splash_verification_document" = "Lado posterior";
    "photopay_back_verification_document" = "Ponga el lado trasero del documento en el marco y espere al que se haga el escaneo automático.";
    "photopay_camera_permission_denied" = "{font:@Medium}%@{/font} no tiene permiso para usar la cámara.\n\nVaya a:\n• {font:@Medium}Ajustes{/font}\n• {font:@Medium}%@{/font}\n• Asegúrese de que {font:@Medium}l la cámara{/font} esté activada";
    "photopay_close" = "Cancelar";
    "photopay_done_splash_verification_document" = "Escaneo del documento realizado";
    "photopay_front_splash_verification_document" = "Lado frontal";
    "photopay_front_verification_document" = "Ponga el lado delantero del documento en el marco y espere a que se haga el escaneo automático.";
    "photopay_grant_camera_permission_button_title" = "Otorgar permiso a la cámara";
    "photopay_id_position_tooltip" = "Ponga la tarjeta identificativa en este marco";


## Respuesta de la SDK 
**1. Estructura encargada de la definición del estado de validación exitoso:**

La SDK dará respuesta mediante dos métodos o promesas de respuesta, que pertenecen al estructura  `BDIVDelegate`:

          func BDIVResponseSuccess(bdivResult: AnyObject) {       
              let idmResultFinal = bdivResult as! ResponseIV        
              print(String(describing: idmResultFinal))           
          }        

          func BDIVResponseError(error: AnyObject) {
              if let errorR = error as? BDIVError {
                  print(errorR.message)   
              }
          }

## Estructura para el retorno de la información

Los siguientes parámetros permiten el retorno de la información capturada por el sistema mediante la promesa de respuesta o evento `BDIVResponseSuccess`:

    func BDIVResponseSuccess(bdivResult: AnyObject) {       
    		   let responseIV = bdivResult as! ResponseIV        
    		   
      lblNombre.text = responseIV?.result.fullName ?? ""
      lblCIU.text = responseIV?.result.documentNumber ?? ""
      lblDate.text = responseIV?.result.dateOfBirth?.originalDateString ?? ""
      if(responseIV?.result.faceImage != nil)
      {
        if let image = responseIV?.result.faceImage?.image {
            self.imgAlphaUser.image = image
            self.imgAlphaUser.makeRounded(borderWidth: 2, borderColor: UIColor.clear.cgColor)
            self.imgUser.image = image
            self.imgUser.makeRounded(borderWidth: 5, borderColor: UIColor.clear.cgColor)
        }
      }        
    }        

Si el parámetro `IsFirstTransaction`, es True, nos indica que es un retorna de la primera transacción, donde se obtiene la imágene que se debe enviar al segundo consumo.

## Posibles Errores
**1. Error con parámetros vacíos**
Los siguientes parámetros son necesarios para la activación de la SDK por lo tanto su valor no debe ser vacío.

Parámetro | Valor
------------ | -------------
contractID | String
userID  | String

Mostrará el siguiente error por consola:

    parameters cannot be empty


## Requerimientos
•	Tecnologías
iOS 12 en adelante
•	Alamofire
5.5.0 / Swift Package Manager
