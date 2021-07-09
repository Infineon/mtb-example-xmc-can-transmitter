# XMC MCU: CAN Transmitter

This example demonstrates how to transmit CAN messages over the CAN bus using the XMC MCU. This example can be used with the [CAN Receiver](https://github.com/cypresssemiconductorco/mtb-example-xmc-can-receiver) example running on another board.

## Requirements

- [ModusToolbox&trade; software](https://www.cypress.com/products/modustoolbox-software-environment) v2.3
- [SEGGER J-Link software](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)
- Programming Language: C
- Associated Parts: All [XMC™ MCU](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/) parts

## Supported Toolchains (make variable 'TOOLCHAIN')

- GNU Arm® Embedded Compiler v9.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`

## Supported Kits (make variable 'TARGET')

- [XMC1400 Boot Kit](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc14_boot_001/) (`KIT_XMC14_BOOT_001`) - Default value of `TARGET`
- [XMC4700 Relax Kit](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc47_relax_v1/) (`KIT_XMC47_RELAX_V1`)

## Hardware Setup

This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.

**Note:** The CAN bus lines (signals CANH and CANL) of the onboard transceiver in the KIT_XMC47_RELAX_V1 kit is not terminated by a 120-ohm resistor and must be terminated externally. Add a 120-ohm termination resistor between the CANH and CANL pins (X2.33 and X2.35 respectively) for the KIT_XMC47_RELAX_V1 kit. 

Two XMC boards are required to test this code example: one for the XMC MCU CAN Transmitter application and the other for the [XMC MCU: CAN Receiver](https://github.com/cypresssemiconductorco/mtb-example-xmc-can-receiver) application. See Supported Kits for the list of kits supported by this code example. Connect the CANH and CANL of one board to the CANH and CANL of the other board respectively to establish CAN communication between the transmitter and the receiver node. Also connect the ground pin of both boards together.

| Development Board | Signal Name | Pin Header in Board |
| -- | -- | -- |
| KIT_XMC14_BOOT_001 | CANH | J102.H |
| KIT_XMC14_BOOT_001 | CANL | J102.L |
| KIT_XMC47_RELAX_V1 | CANH | X2.33 |
| KIT_XMC47_RELAX_V1 | CANL | X2.35 |

**Hardware Setup**

<img src="images/hardware_setup.jpg" alt="Hardware Setup" width="700"/>

## Software Setup

This example requires no additional software or tools.

## Using the Code Example

Create the project and open it using one of the following:

<details open><summary><b>In Eclipse IDE for ModusToolbox</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox Application**). This launches the [Project Creator](http://www.cypress.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.cypress.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   If you want to use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. Optionally, change the suggested **New Application Name**.

5. Enter the local path in the **Application(s) Root Path** field to indicate where the application needs to be created.

   Applications that can share libraries can be placed in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox User Guide](https://www.cypress.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox install directory}/ide_{version}/docs/mt_ide_user_guide.pdf*).

</details>

<details open><summary><b>In Command-line Interface (CLI)</b></summary>

ModusToolbox provides the Project Creator as both a GUI tool and a command line tool to easily create one or more ModusToolbox applications. See the "Project Creator Tools" section of the [ModusToolbox User Guide](https://www.cypress.com/ModusToolboxUserGuide) for more details.

Alternatively, you can manually create the application using the following steps:

1. Download and unzip this repository onto your local machine, or clone the repository.

2. Open a CLI terminal and navigate to the application folder.

   On Linux and macOS, you can use any terminal application. On Windows, open the **modus-shell** app from the Start menu.

   **Note:** The cloned application contains a default BSP file (*TARGET_xxx.mtb*) in the *deps* folder. Use the [Library Manager](https://www.cypress.com/ModusToolboxLibraryManager) (`make modlibs` command) to select and download a different BSP file, if required. If the selected kit does not have the required resources or is not [supported](#supported-kits-make-variable-target), the application may not work.

3. Import the required libraries by executing the `make getlibs` command.

Various CLI tools include a `-h` option that prints help information to the terminal screen about that tool. For more details, see the [ModusToolbox User Guide](https://www.cypress.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>

<details open><summary><b>In Third-party IDEs</b></summary>

**Note:** Only VS Code is supported.

1. Follow the instructions from the **In Command-line Interface (CLI)** section to create the application, and import the libraries using the `make getlibs` command.

2. Export the application to a supported IDE using the `make <ide>` command.

   For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox User Guide](https://www.cypress.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox install directory}/docs_{version}/mtb_user_guide.pdf*).

3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

</details>

## Operation

1. Connect the board to your PC using a micro-USB cable through the debug USB connector.

2. Program the board using Eclipse IDE for ModusToolbox:

   1. Select the application project in the Project Explorer.

   2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (JLink)**.

3. Connect the second board running the CAN Receiver example as described in the [Hardware Setup](#hardware-setup) section. 

4. Confirm that the USER LED toggles on the tranmsitter board, which confirms that the CAN frame is transmitted periodically.

5. Press the USER button on the transmitter board and confirm that the USER LED2 on the receiver board is updated accordingly. 

**Note:** KIT_XMC14_BOOT_001 does not have an onboard user switch. Connect an external switch to pin P4.4 to test the example. 

## Debugging

You can debug the example to step through the code. In the IDE, use the **\<Application Name> Debug (JLink)** configuration in the **Quick Panel**. For more details, see the "Program and Debug" section in the [Eclipse IDE for ModusToolbox User Guide](https://www.cypress.com/MTBEclipseIDEUserGuide).

## Design and Implementation

In this code example, the CAN Node 1 is linked with message object 0 (MO0), which is configured to transmit a single byte over the CAN bus. The status of the USER button is sent over the CAN bus for every 100 ms. Successful transmission of the message is indicated by toggling the USER LED. 

**Firmware Flow**

![Firmware Flow](images/firmware_flow.jpg)

### Resources and Settings

The project uses a custom design.modus file since the following settings were modified in the default design.modus file.

**CAN RX pin settings**

![CAN RX pin settings](images/can_rx_settings.jpg)

**CAN TX pin settings**

![CAN TX pin settings](images/can_tx_settings.jpg)

**User Button pin settings**

![User Button pin settings](images/user_button_settings.jpg)

## Related Resources

| Kit Guides                                            |                                                              |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [XMC4700/XMC4800 Relax Kit Series-V1](https://www.infineon.com/dgdl/Infineon-Board_User_Manual_XMC4700_XMC4800_Relax_Kit_Series-UM-v01_02-EN.pdf?fileId=5546d46250cc1fdf01513f8e052d07fc) – Board User‘s Manual | Describes the schematic and hardware of the XMC4700/XMC4800 Relax Kit Series-V1, equipped with an Arm® Cortex®-M4 based XMC™ Microcontroller from Infineon Technologies AG. |
| [XMC1400 Boot Kit](https://www.infineon.com/dgdl/Infineon-Board_Users_Manual_XMC1400_Boot_Kit.pdf-UM-v01_00-EN.pdf?fileId=5546d462525dbac401527815f9a073fd) – Board User‘s Manual | Describes the schematic and hardware of XMC1400 Boot Kit for application code development on the XMC1404-Q064X0200 device.|
| **Code Examples**                                            |                                                              |
| [Using ModusToolbox](https://github.com/cypresssemiconductorco/Code-Examples-for-ModusToolbox-Software) |
| **Device Documentation**                                     |                                                              |
| [XMC1000 Family Datasheets](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc1000-industrial-microcontroller-arm-cortex-m0/#document-group-myInfineon-49) | [XMC1000 Family Technical Reference Manuals](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc1000-industrial-microcontroller-arm-cortex-m0/#document-group-myInfineon-44) |
| [XMC4000 Family Datasheets](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc4000-industrial-microcontroller-arm-cortex-m4/#document-group-myInfineon-49) | [XMC4000 Family Technical Reference Manuals](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc4000-industrial-microcontroller-arm-cortex-m4/#document-group-myInfineon-44) |
| **Development Kits**                                         | Buy at www.infineon.com                                       |
| [KIT_XMC14_BOOT_001](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc14_boot_001/) Boot Kit XMC1400 | [KIT_XMC47_RELAX_V1](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc47_relax_v1/) XMC4700 Relax Kit |
| **Libraries**                                                 |                                                              |
| XMC Peripheral Library (XMCLib) and docs  | [mtb-xmclib-cat3](https://github.com/cypresssemiconductorco/mtb-xmclib-cat3) on GitHub |
| **Tools**                                                    |                                                              |
| [Eclipse IDE for ModusToolbox](https://www.cypress.com/modustoolbox)     | The cross-platform, Eclipse-based IDE for IoT designers that supports application configuration and development targeting converged MCU and wireless systems.             |

## Other Resources

Infineon provides a wealth of data at www.infineon.com to help you select the right device, and quickly and effectively integrate it into your design.

For XMC MCU devices, see [32-bit XMC™ Industrial Microcontroller based on Arm® Cortex®-M](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/).

## Document History

Document Title: *CE232628* - *XMC MCU: CAN Transmitter*

| Version | Description of Change |
| ------- | --------------------- |
| 1.0.0   | New code example      |
------

All other trademarks or registered trademarks referenced herein are the property of their respective owners.

![banner](images/ifx_logo_rgb.jpg)

© 2021 Infineon Technologies AG

All Rights Reserved.

### Legal Disclaimer

The information given in this document shall in no event be regarded as a guarantee of conditions or characteristics. With respect to any examples or hints given herein, any typical values stated herein and/or any information regarding the application of the device, Infineon Technologies hereby disclaims any and all warranties and liabilities of any kind, including without limitation, warranties of non-infringement of intellectual property rights of any third party.

### Information

For further information on technology, delivery terms and conditions and prices, please contact the nearest Infineon Technologies Office (www.infineon.com).

### Warnings

Due to technical requirements, components may contain dangerous substances. For information on the types in question, please contact the nearest Infineon Technologies Office.

Infineon Technologies components may be used in life-support devices or systems only with the express written approval of Infineon Technologies, if a failure of such components can reasonably be expected to cause the failure of that life-support device or system or to affect the safety or effectiveness of that device or system. Life support devices or systems are intended to be implanted in the human body or to support and/or maintain and sustain and/or protect human life. If they fail, it is reasonable to assume that the health of the user or other persons may be endangered.

-------------------------------------------------------------------------------
