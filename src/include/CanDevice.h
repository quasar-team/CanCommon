#ifndef SRC_INCLUDE_CANDEVICE_H_
#define SRC_INCLUDE_CANDEVICE_H_

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "CanDeviceArguments.h"
#include "CanDiagnostics.h"
#include "CanFrame.h"

enum class CanReturnCode {
  SUCCESS,
  UNKNOWN_OPEN_ERROR,
  SOCKET_ERROR,
  TOO_MANY_CONNECTIONS,
  TIMEOUT,
  NOT_CONNECTED,
  UNACKNOWLEDGMENT,
  INTERNAL_API_ERROR,
  UNKNOWN_SEND_ERROR,
  CAN_NACK,
  CAN_TX_ERROR,
  CAN_TX_BUFFER_OVERFLOW,
  CAN_LOST_ARBITRATION,
  CAN_INVALID_BITRATE,
  UNKNOWN_CLOSE_ERROR,
};

std::ostream& operator<<(std::ostream& os, CanReturnCode code);

/**
 * @brief This struct represents a CAN device.
 *
 * It provides methods for opening, closing, sending, and receiving CanFrame,
 * as well as accessing device information and diagnostics.
 */
struct CanDevice {
  CanReturnCode open();
  CanReturnCode close();
  CanReturnCode send(const CanFrame& frame);
  std::vector<CanReturnCode> send(const std::vector<CanFrame>& frames);
  CanDiagnostics diagnostics();

  /**
   * @brief Returns the name of the CAN device vendor.
   *
   * This function retrieves the name of the vendor that manufactures the CAN
   * device.
   *
   * @return A string representing the name of the CAN device vendor.
   */
  inline std::string vendor_name() const { return m_vendor; }

  /**
   * @brief Returns a constant reference to the CanDeviceArguments object.
   *
   * This function provides access to the CanDeviceArguments object, which
   * contains configuration parameters for the CAN device.
   *
   * @return A constant reference to the CanDeviceArguments object.
   */
  inline const CanDeviceArguments& args() const { return m_args; }

  virtual ~CanDevice() = default;

  static std::unique_ptr<CanDevice> create(
      std::string_view vendor, const CanDeviceArguments& configuration);

 protected:
  /**
   * @brief Constructor for the CanDevice class.
   *
   * Initializes the CanDevice object with the provided vendor name and
   * CanDeviceArguments.
   *
   * @param vendor_name A string view representing the name of the CAN device
   * vendor.
   * @param args A constant reference to the CanDeviceArguments object, which
   * contains configuration parameters for the CAN device.
   */
  CanDevice(std::string_view vendor_name, const CanDeviceArguments& args)
      : m_vendor{vendor_name}, m_args{args} {}

  /**
   * @brief Pure virtual functions for vendor-specific CAN device operations.
   *
   * These functions are intended to be overridden by specific vendor
   * implementations to provide the necessary functionality for opening,
   * closing, sending, and retrieving diagnostics from the CAN device.
   */
  virtual CanReturnCode vendor_open() = 0;

  /**
   * @brief Pure virtual functions for vendor-specific CAN device operations.
   *
   * These functions are intended to be overridden by specific vendor
   * implementations to provide the necessary functionality for opening,
   * closing, sending, and retrieving diagnostics from the CAN device.
   */
  virtual CanReturnCode vendor_close() = 0;

  /**
   * @brief Pure virtual functions for vendor-specific CAN device operations.
   *
   * These functions are intended to be overridden by specific vendor
   * implementations to provide the necessary functionality for opening,
   * closing, sending, and retrieving diagnostics from the CAN device.
   */
  virtual CanReturnCode vendor_send(const CanFrame& frame) = 0;

  /**
   * @brief Pure virtual functions for vendor-specific CAN device operations.
   *
   * These functions are intended to be overridden by specific vendor
   * implementations to provide the necessary functionality for opening,
   * closing, sending, and retrieving diagnostics from the CAN device.
   */
  virtual CanDiagnostics vendor_diagnostics() = 0;

  /**
   * @brief Handles incoming CAN frames.
   *
   * This function is called whenever a CAN frame is received by the CAN device.
   * It passes the received frame to the receiver function specified in the
   * CanDeviceArguments object.
   *
   * @param frame A const reference to the received CanFrame.
   */
  void received(const CanFrame& frame) { m_args.receiver(frame); }

 private:
  const std::string m_vendor;
  const CanDeviceArguments m_args;
};

#endif  // SRC_INCLUDE_CANDEVICE_H_
