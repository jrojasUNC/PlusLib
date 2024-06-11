/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusWinProbeVideoSource_h
#define __vtkPlusWinProbeVideoSource_h

#include <thread>

#include "vtkPlusDataCollectionExport.h"
#include "vtkPlusUsDevice.h"
#include "vtkPlusUsImagingParameters.h"

/*!
 \class vtkPlusWinProbeVideoSource
 \brief Class for acquiring ultrasound images from WinProbe ultrasound systems.

 Requires PLUS_USE_WINPROBE_VIDEO option in CMake.
 Requires the WinProbeSDK.

 \ingroup PlusLibDataCollection.
*/
class vtkPlusDataCollectionExport vtkPlusWinProbeVideoSource : public vtkPlusUsDevice
{
public:
  /*! Constructor for a smart pointer of this class*/
  static vtkPlusWinProbeVideoSource* New();
  vtkTypeMacro(vtkPlusWinProbeVideoSource, vtkPlusDevice);
  virtual void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;
  static const char* SET_FREEZE;
  static const char* GET_FREEZE;
  static const char* SET_TGC;
  static const char* GET_TGC;
  static const char* SET_ALL_FOCAL_DEPTHS;
  static const char* SET_FOCAL_DEPTH;
  static const char* GET_FOCAL_DEPTH;
  static const char* SET_ALL_ARFI_FOCAL_DEPTHS;
  static const char* SET_ARFI_FOCAL_DEPTH;
  static const char* GET_ARFI_FOCAL_DEPTH;
  static const char* SET_B_MULTIFOCAL_ZONE_COUNT;
  static const char* GET_B_MULTIFOCAL_ZONE_COUNT;
  static const char* SET_FIRST_GAIN_VALUE;
  static const char* GET_FIRST_GAIN_VALUE;
  static const char* SET_TGC_OVERALL_GAIN;
  static const char* GET_TGC_OVERALL_GAIN;
  static const char* SET_SPATIAL_COMPOUND_ENABLED;
  static const char* GET_SPATIAL_COMPOUND_ENABLED;
  static const char* GET_SPATIAL_COMPOUND_ANGLE;
  static const char* SET_SPATIAL_COMPOUND_COUNT;
  static const char* GET_SPATIAL_COMPOUND_COUNT;
  static const char* SET_MMODE_ENABLED;
  static const char* GET_MMODE_ENABLED;
  static const char* SET_M_REVOLVING_ENABLED;
  static const char* GET_M_REVOLVING_ENABLED;
  static const char* SET_RF_MODE_ENABLED;
  static const char* GET_RF_MODE_ENABLED;
  static const char* SET_MPR_FREQUENCY;
  static const char* GET_MPR_FREQUENCY;
  static const char* SET_M_LINE_INDEX;
  static const char* GET_M_LINE_INDEX;
  static const char* SET_M_LINE_COUNT;
  static const char* GET_M_LINE_COUNT;
  static const char* SET_M_WIDTH;
  static const char* GET_M_WIDTH;
  static const char* SET_M_DEPTH;
  static const char* GET_M_DEPTH;
  static const char* SET_DECIMATION;
  static const char* GET_DECIMATION;
  static const char* SET_B_FRAME_RATE_LIMIT;
  static const char* GET_B_FRAME_RATE_LIMIT;
  static const char* SET_B_HARMONIC_ENABLED;
  static const char* GET_B_HARMONIC_ENABLED;
  static const char* SET_B_BUBBLE_CONTRAST_ENABLED;
  static const char* GET_B_BUBBLE_CONTRAST_ENABLED;
  static const char* SET_B_AMPLITUDE_MODULATION_ENABLED;
  static const char* GET_B_AMPLITUDE_MODULATION_ENABLED;
  static const char* SET_B_TRANSMIT_LOCKED;
  static const char* GET_B_TRANSMIT_LOCKED;
  static const char* SET_B_TRANSMIT_CURRENT;
  static const char* GET_B_TRANSMIT_CURRENT;
  static const char* SET_B_TRANSMIT_CYCLE_COUNT;
  static const char* GET_B_TRANSMIT_CYCLE_COUNT;
  static const char* SET_B_TRANSMIT_FNUMBER;
  static const char* GET_B_TRANSMIT_FNUMBER;
  static const char* SET_B_APODIZATION_FNUMBER;
  static const char* GET_B_APODIZATION_FNUMBER;
  static const char* SET_B_TX_FILTER_COEFFICIENT_SET;
  static const char* GET_B_TX_FILTER_COEFFICIENT_SET;
  static const char* GET_TRANSDUCER_INTERNAL_ID;
  static const char* SET_ARFI_ENABLED;
  static const char* GET_ARFI_ENABLED;
  static const char* SET_ARFI_START_SAMPLE;
  static const char* GET_ARFI_START_SAMPLE;
  static const char* SET_ARFI_STOP_SAMPLE;
  static const char* GET_ARFI_STOP_SAMPLE;
  static const char* SET_ARFI_PRE_PUSH_LINE_REPEAT_COUNT;
  static const char* GET_ARFI_PRE_PUSH_LINE_REPEAT_COUNT;
  static const char* SET_ARFI_POST_PUSH_LINE_REPEAT_COUNT;
  static const char* GET_ARFI_POST_PUSH_LINE_REPEAT_COUNT;
  static const char* SET_ARFI_INTER_SET_DELAY;
  static const char* GET_ARFI_INTER_SET_DELAY;
  static const char* SET_ARFI_INTER_PUSH_DELAY;
  static const char* GET_ARFI_INTER_PUSH_DELAY;
  static const char* SET_ARFI_LINE_TIMER;
  static const char* GET_ARFI_LINE_TIMER;
  static const char* SET_ARFI_TX_CYCLE_COUNT;
  static const char* GET_ARFI_TX_CYCLE_COUNT;
  static const char* SET_ARFI_TX_CYCLE_WIDTH;
  static const char* GET_ARFI_TX_CYCLE_WIDTH;
  static const char* SET_ARFI_TX_TX_CYCLE_COUNT;
  static const char* GET_ARFI_TX_TX_CYCLE_COUNT;
  static const char* SET_ARFI_TX_TX_CYCLE_WIDTH;
  static const char* GET_ARFI_TX_TX_CYCLE_WIDTH;
  static const char* SET_ARFI_PUSH_CONFIG;
  static const char* GET_ARFI_PUSH_CONFIG;
  static const char* GET_FPGA_REV_DATE_STRING;
  static const char* GET_X8BF_ENABLED;
  static const char* UV_SEND_COMMAND;
  static const char* IS_SCANNING;

  /*! Specify the device connected to this class */
  virtual bool IsTracker() const { return false; }

  /*! Read configuration from xml data */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* config);

  /*! Write configuration to xml data */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* config);

  /*! Set changed imaging parameter to device */
  PlusStatus InternalApplyImagingParameterChange() override;

  /* Set the transmit frequency of US probe (MHz) */
  PlusStatus SetTransmitFrequencyMHz(float frequency);

  /* Get the transmit frequency of US probe (MHz) */
  float GetTransmitFrequencyMHz();

  /* Set the voltage of US probe (percent?) */
  PlusStatus SetVoltage(uint8_t voltage);

  /* Get the voltage of US probe (percent?) */
  uint8_t GetVoltage();

  /* Set the scan depth of US probe (mm) */
  PlusStatus SetScanDepthMm(float depth);

  /* Get the scan depth of US probe (mm) */
  float GetScanDepthMm();

   /* Set the scan depth of US probe (mm) */
  PlusStatus SetSSDecimation(uint8_t value);

  /* Get the scan depth of US probe (mm) */
  uint8_t GetSSDecimation();

  /* Get the width of current transducer (mm) */
  float GetTransducerWidthMm();

  /* Get the pixel spacing for all 3 axes (mm) */
  const double* GetCurrentPixelSpacingMm();

  /* Get the TGC value, index 0 to 7, value 0.0 to 40.0 */
  double GetTimeGainCompensation(int index);

  /* Set the TGC value, index 0 to 7, value 0.0 to 40.0 */
  PlusStatus SetTimeGainCompensation(int index, double value);

  /* Get the TGC First Gain Value near transducer face */
  double GetFirstGainValue();

  /* Set the TGC First Gain Value near transducer face */
  PlusStatus SetFirstGainValue(double value);

  /* Get the current overall gain value, value 0.0 to 40.0 */
  double GetOverallTimeGainCompensation();

  /* Set an overall gain value, value 0.0 to 40.0 */
  PlusStatus SetOverallTimeGainCompensation(double value);

  /* Get the B-Mode focal depth at a specific index, index 0 to 3 */
  float GetFocalPointDepth(int index);

  /* Set the B-Mode focal depth at a specific index, index 0 to 3 */
  PlusStatus SetFocalPointDepth(int index, float depth);

  /* Get the ARFI focal depth at a specific index, index 0 to 5

  Index 0: Tracking Depth
  Index 1-5: Push Depth
  */
  float GetARFIFocalPointDepth(int index);

  /*
  Set the ARFI focal depth at a specific index, index 0 to 5

  Index 0: Tracking Depth
  Index 1-5: Push Depth
  */
  PlusStatus SetARFIFocalPointDepth(int index, float depth);

  /* Get the number of active focal zones for B-Mode, count 1 to 4 */
  int32_t GetBMultiFocalZoneCount();

  /* Set the number of active focal zones for B-Mode, count 1 to 4 */
  PlusStatus SetBMultiFocalZoneCount(int32_t count);

  /* Get if the connected engine has an x8 beamformer. */
  bool GetARFIIsX8BFEnabled();

  /* Set the number of states in the transmit pulse. 1-16 */
  PlusStatus SetARFITxTxCycleCount(uint16_t propertyValue);

  /* Get the number of states in the transmit pulse. 1-16 */
  uint16_t GetARFITxTxCycleCount();

  /* Set the width of the tx cycle. Determines the transmit frequency for non apodized transmits. 1-255 */
  PlusStatus SetARFITxTxCycleWidth(uint8_t propertyValue);

  /* Get the width of the tx cycle. Determines the transmit frequency for non apodized transmits. 1-255 */
  uint8_t GetARFITxTxCycleWidth();

  /* Set the number of cycles in the ARFI push pulse. */
  PlusStatus SetARFITxCycleCount(uint16_t propertyValue);

  /* Get the number of cycles in the ARFI push pulse. */
  uint16_t GetARFITxCycleCount();

  /* Set the frequency of the push pulse. */
  PlusStatus SetARFITxCycleWidth(uint8_t propertyValue);

  /* Get the frequency of the push pulse. */
  uint8_t GetARFITxCycleWidth();

  /* Whether or not to use device's built-in frame reconstruction.
   * This should not be changed in the middle of acquisition as it
   * breaks some assumptions about frame size and timestamps. */
  void SetUseDeviceFrameReconstruction(bool value) { m_UseDeviceFrameReconstruction = value; }

  /* Whether or not to use device's built-in frame reconstruction */
  bool GetUseDeviceFrameReconstruction() { return m_UseDeviceFrameReconstruction; }

  /*! Set ON/OFF of collecting US data. */
  PlusStatus FreezeDevice(bool freeze);

  /*! Checks whether the device is frozen or live. */
  bool IsFrozen();

  /*! Checks whether the device is scanning or not. It could be in the process of resetting the sequencer. */
  bool IsScanning();

  /*! Get the FPGA version string. */
  std::string GetFPGARevDateString();

  /*! Sets GUID of the probe type to be used. */
  PlusStatus SetTransducerID(std::string guid);

  /*! Gets GUID of the probe type to be used. */
  std::string GetTransducerID();

  /*! Sets the noise floor for intensity range compression. */
  void SetMinValue(const uint16_t minValue) { m_MinValue = minValue; }

  /*! Gets the noise floor for intensity range compression. */
  uint16_t GetMinValue() const { return m_MinValue; }

  /*! Sets the typical high value for intensity range compression. */
  void SetMaxValue(const uint16_t maxValue) { m_MaxValue = maxValue; }

  /*! Gets the typical high value for intensity range compression. */
  uint16_t GetMaxValue() const { return m_MaxValue; }

  /*! Sets the threshold value for switching from log to linear mapping for intensity range compression. */
  void SetLogLinearKnee(const uint16_t threshold) { m_Knee = threshold; }

  /*! Gets the threshold value for switching from log to linear mapping for intensity range compression. */
  uint16_t GetLogLinearKnee() const { return m_Knee; }

  /*! Sets the maximum output value for log mapping of intensity range. */
  void SetLogMax(const uint8_t threshold) { m_OutputKnee = threshold; }

  /*! Gets the maximum output value for log mapping of intensity range. */
  uint8_t GetLogMax() const { return m_OutputKnee; }

  void SetSpatialCompoundEnabled(bool value);
  bool GetSpatialCompoundEnabled();

  /*!
  Sets the number of +/- degree angles to use.

  Spatial Compounding Count of:
  1 -> 0 degrees and +/- 10 degrees
  2 -> 0 degrees and +/- 6 degrees and +/- 12 degrees
  3 -> 0 degrees and +/- 4 degrees and +/- 8 degrees and +/- 12 degrees
  4 -> 0 degrees and +/- 3 degrees and +/- 6 degrees and +/- 9 degrees and +/- 12 degrees
  */
  void SetSpatialCompoundCount(int32_t value);
  int32_t GetSpatialCompoundCount();

  /*!
  Gets the delta between angle values used.

  The beamformers assume a static array of possible angles.
  Spatial Compounding Count=3 will return a Spatial Compound Angle of 4 degrees.
  */
  float GetSpatialCompoundAngle();

  void SetBHarmonicEnabled(bool value);
  bool GetBHarmonicEnabled();

  void SetBBubbleContrastEnabled(bool value);
  bool GetBBubbleContrastEnabled();

  void SetBAmplitudeModulationEnabled(bool value);
  bool GetBAmplitudeModulationEnabled();

  void SetBTransmitLocked(bool value);
  bool GetBTransmitLocked();

  void SetBTransmitCurrent(int value);
  int GetBTransmitCurrent();

  void SetBTransmitCycleCount(uint16_t value);
  uint16_t GetBTransmitCycleCount();

  void SetBTransmitFNumber(double value);
  double GetBTransmitFNumber();

  void SetBApodizationFNumber(double value);
  double GetBApodizationFNumber();

  void SetBTXFilterCoefficientSet(int32_t value);   // set actual filter number
  int32_t GetBTXFilterCoefficientSet();

  void SetBRFEnabled(bool value);
  bool GetBRFEnabled();

  void SetMModeEnabled(bool value);
  bool GetMModeEnabled();

  void SetMRevolvingEnabled(bool value);
  bool GetMRevolvingEnabled();

  void SetMPRFrequency(int32_t value);
  int32_t GetMPRFrequency();

  void SetMLineIndex(int32_t value);
  int32_t GetMLineIndex();

  void SetMWidth(int value);
  int GetMWidth();

  void SetMWidthLines(int32_t value);
  int32_t GetMWidthLines();

  void SetMAcousticLineCount(int32_t value);
  int32_t GetMAcousticLineCount();

  void SetMDepth(int32_t value);
  int32_t GetMDepth();

  void SetBFrameRateLimit(int32_t value);
  int32_t GetBFrameRateLimit();

  void SetARFIEnabled(bool value);
  bool GetARFIEnabled();
  /*! If running in ARFI mode, does an ARFI push. Otherwise does nothing and returns failure status. */
  PlusStatus ARFIPush(uint8_t maximumVoltage = 50);
  void SetARFIStartSample(int32_t value);
  int32_t GetARFIStartSample();

  void SetARFIStopSample(int32_t value);
  int32_t GetARFIStopSample();

  /* Set the time value in microseconds between ARFI tracking lines. Timer Values cannot exceed 2000uS. */
  PlusStatus SetARFILineTimer(uint16_t propertyValue);

  /* Get the time value in microseconds between ARFI tracking lines. */
  uint16_t GetARFILineTimer();

  /* Set the number of repeats for the tracking lines before the push. */
  PlusStatus SetARFIPrePushLineRepeatCount(int32_t propertyValue);

  /* Get the number of repeats for the tracking lines before the push. */
  int32_t GetARFIPrePushLineRepeatCount();

  /* Set the number of repeats for the tracking lines after the push. */
  PlusStatus SetARFIPostPushLineRepeatCount(int32_t propertyValue);

  /* Get the number of repeats for the tracking lines after the push. */
  int32_t GetARFIPostPushLineRepeatCount();

  /*!
  Set the integer increment (1.05ms per increment) to delay after completion of the ARFIPushConfigurationString before it begins live streaming B-Mode frames again.

  Setting to 0 will default to the clinical delay of approximately 1 second.

  The interset delay is a post ARFI configuration string delay.
  Example: "1,33,44;1,41,52;1,49,60;1,57,68;1,65,76;1,73,84;2,36,44;2,44,52;2,52,60;2,60,68;2,68,76;2,76,84(interset)"
  */
  PlusStatus SetARFIInterSetDelay(int32_t propertyValue);

   /* Get the integer increment (1.05ms per increment) to delay after completion of the ARFIPushConfigurationString before it begins live streaming B-Mode frames again. */
  int32_t GetARFIInterSetDelay();

  /*!
  Set the integer increment (1.05ms per increment) to delay after each push of the ARFIPushConfigurationString.

  Example: "1,33,44;(interpush)1,41,52;(interpush)1,49,60;(interpush)1,57,68;(interpush)1,65,76;(interpush)1,73,84;(interpush)(interset)"
  */
  PlusStatus SetARFIInterPushDelay(int32_t propertyValue);

  /* Get the integer increment (1.05ms per increment) to delay after each push of the ARFIPushConfigurationString. */
  int32_t GetARFIInterPushDelay();

  int GetTransducerInternalID();

  /*!
  Only for X8BF devices. Set a custom ARFI push configuration.

  The first number is the push focus depth number in the ARFI focal depths. (Index 1 through 5 are for push focus).
  The second number is the push line location. (int)
  The third number is the tracking line location. (int)
  Then the number of sets determines the number of pushes.

  Examples shown on multiple lines for easier viewing, but it is a single string.
  Example 1) Push with the same focus at 6 lateral positions and then repeat with a new push focus for total of 5 different push focuses used.
  "1,40,48;1,48,56;1,56,64;1,64,72;1,72,80;1,80,88;
   2,40,48;2,48,56;2,56,64;2,64,72;2,72,80;2,80,88;
   3,40,48;3,48,56;3,56,64;3,64,72;3,72,80;3,80,88;
   4,40,48;4,48,56;4,56,64;4,64,72;4,72,80;4,80,88;
   5,40,48;5,48,56;5,56,64;5,64,72;5,72,80;5,80,88"

  Example 2) Repeat the same push 3 times and then move to a new lateral position with 6 different lateral positions total.
  "1,40,48;1,40,48;1,40,48;
   1,48,56;1,48,56;1,48,56;
   1,56,64;1,56,64;1,56,64;
   1,64,72;1,64,72;1,64,72;
   1,72,80;1,72,80;1,72,80;
   1,80,88;1,80,88;1,80,88"
  */
  void SetARFIPushConfigurationString(std::string pushConfiguration);
  std::string GetARFIPushConfigurationString();

  enum class Mode
  {
    B = 0, // only B mode
    BRF, // RF mode with reference B mode
    RF, // RF mode only
    M, // M mode
    PW, // Pulsed Wave Doppler
    ARFI, // Acoustic Radiation Force Impulse
    CFD // Color-Flow Doppler
  };

  PlusStatus SetExtraSourceMode(Mode mode);

  /*! Sets the ultrasound imaging mode. */
  void SetMode(Mode mode)
  {
    m_Mode = mode;
  }

  /*! Gets the ultrasound imaging mode. */
  Mode GetMode()
  {
    return m_Mode;
  }

  Mode StringToMode(std::string modeString);
  std::string ModeToString(Mode mode);

  int32_t MWidthFromSeconds(int value);
  int MSecondsFromWidth(int32_t value);

  std::vector<double> GetPrimarySourceSpacing();
  std::vector<double> GetExtraSourceSpacing();

  PlusStatus SendCommand(const char * command);

protected:
  /*! Constructor */
  vtkPlusWinProbeVideoSource();

  /*! Destructor */
  ~vtkPlusWinProbeVideoSource();

  /*! Device-specific connect */
  virtual PlusStatus InternalConnect() VTK_OVERRIDE;

  /*! Device-specific disconnect */
  virtual PlusStatus InternalDisconnect() VTK_OVERRIDE;

  /*! Device-specific recording start */
  virtual PlusStatus InternalStartRecording() VTK_OVERRIDE;

  /*! Device-specific recording stop */
  virtual PlusStatus InternalStopRecording() VTK_OVERRIDE;

  /*! The internal function which actually does the grab. */
  PlusStatus InternalUpdate();

  /*! Updates internal spacing based on current depth */
  void AdjustSpacing(bool value);

  /*! Updates buffer size based on current depth */
  void AdjustBufferSizes();

  friend int __stdcall frameCallback(int length, char* data, char* hHeader, char* hGeometry, char* hModeFrameHeader);
  void ReconstructFrame(char* data, std::vector<uint8_t>& buffer, const FrameSizeType& frameSize);
  void FlipTexture(char* data, const FrameSizeType& frameSize, int rowPitch);
  void FrameCallback(int length, char* data, char* hHeader, char* hGeometry);

  float m_ScanDepth = 26.0; //mm
  float m_TransducerWidth = 38.1; //mm
  float m_Frequency = 10.9; //MHz
  uint8_t m_Voltage = 40;
  std::string m_TransducerID; //GUID
  std::string m_FPGAVersion;
  double m_ADCfrequency = 60.0e6; //MHz
  double m_TimestampOffset = 0; //difference between program start time and latest internal timer restart
  double m_RenderedTimestampOffset = 0; //difference between program start time and latest internal timer restart
  double first_timestamp = 0;
  FrameSizeType m_PrimaryFrameSize = { 128, 256, 1 };
  FrameSizeType m_ExtraFrameSize = { 256, 128, 1 };
  std::vector<uint8_t> m_PrimaryBuffer;
  std::vector<uint8_t> m_ExtraBuffer;
  bool m_UseDeviceFrameReconstruction = true;
  igsioFieldMapType m_CustomFields;
  double m_TimeGainCompensation[8];
  double m_OverallTimeGainCompensation = 0;
  float m_FocalPointDepth[4];
  float m_ARFIFocalPointDepth[6];
  uint16_t m_MinValue = 16; //noise floor
  uint16_t m_MaxValue = 16384; //maximum typical value
  uint16_t m_Knee = 4096; // threshold value for switching from log to linear
  uint8_t m_OutputKnee = 64; // log-linear knee in output range
  bool m_SpatialCompoundEnabled = false;
  float m_SpatialCompoundAngle = 10.0f;
  int32_t m_SpatialCompoundCount = 0;
  bool m_MRevolvingEnabled = false;
  int32_t m_BMultiTxCount = 1;
  uint16_t m_ARFITxTxCycleCount = 2;
  uint8_t m_ARFITxTxCycleWidth = 10;
  uint16_t m_ARFITxCycleCount = 4096;
  uint8_t m_ARFITxCycleWidth = 15;
  int32_t m_ARFIStartSample = 0;
  int32_t m_ARFIStopSample = 1024;
  uint16_t m_ARFILineTimer = 100;
  int32_t m_ARFIPrePushLineRepeatCount = 8;
  int32_t m_ARFIPostPushLineRepeatCount = 56;
  int32_t m_ARFIInterSetDelay = 100;
  int32_t m_ARFIInterPushDelay = 100;
  std::string m_ARFIPushConfigurationString = "1,33,44;1,41,52;1,49,60;1,57,68;1,65,76;1,73,84";
  int m_ARFIPushConfigurationCount = 6;
  int32_t m_MPRF = 100;
  int32_t m_MLineIndex = 60;
  int32_t m_MWidth = 256;
  int32_t m_MAcousticLineCount = 0;
  int32_t m_MDepth = 0;
  uint8_t m_SSDecimation = 2;
  double m_FirstGainValue = 15;
  int32_t m_BFrameRateLimit = 0;
  bool m_BHarmonicEnabled = false;
  bool m_BBubbleContrastEnabled = false;
  bool m_BAmplitudeModulationEnabled = false;
  bool m_BTransmitLocked = false;
  int m_BTransmitCurrent = 0;
  uint16_t m_BTransmitCycleCount = 2;
  double m_BTransmitFNumber = 3;
  double m_BApodizationFNumber = 0.5;
  int32_t m_BTXFilterCoefficientSet = 3;      // default filter
  std::vector<vtkPlusDataSource*> m_PrimarySources;
  std::vector<vtkPlusDataSource*> m_ExtraSources;

  Mode m_Mode = Mode::B;

public:
  vtkPlusWinProbeVideoSource(const vtkPlusWinProbeVideoSource&) = delete;
  void operator=(const vtkPlusWinProbeVideoSource&) = delete;
};

#endif
