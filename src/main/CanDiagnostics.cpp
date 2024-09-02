#include "CanDiagnostics.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

std::string CanDiagnostics::to_string() const noexcept {
  std::ostringstream oss;

  print_vector_field<optional_string_vector_t>(oss, log_entries, "Log Entries");

  print_field<optional_string_t>(oss, name, "Name");
  print_field<std::optional<int>>(oss, handle, "Handle");
  print_field<optional_string_t>(oss, mode, "Mode");
  print_field<optional_string_t>(oss, state, "State");
  print_field<std::optional<uint32_t>>(oss, bitrate, "Bitrate");
  print_vector_field<optional_string_vector_t>(oss, connected_clients_addresses,
                                               "Connected Clients");
  print_vector_field<optional_string_vector_t>(
      oss, connected_clients_timestamps, "Connected Clients' Timestamps");
  print_vector_field<optional_uint32_vector_t>(oss, connected_clients_ports,
                                               "Connected clients");

  print_field<std::optional<float>>(oss, temperature, "Temperature");
  print_field<std::optional<uint32_t>>(oss, uptime, "Uptime");
  print_field<std::optional<uint32_t>>(oss, tcp_rx, "TCP Received");
  print_field<std::optional<uint32_t>>(oss, tcp_tx, "TCP Transmitted");
  print_field<std::optional<uint32_t>>(oss, rx, "CAN Received");
  print_field<std::optional<uint32_t>>(oss, tx, "CAN Transmitted");
  print_field<std::optional<uint32_t>>(oss, rx_error, "CAN Receive Error");
  print_field<std::optional<uint32_t>>(oss, tx_error, "CAN Transmit Error");
  print_field<std::optional<uint32_t>>(oss, rx_drop,
                                       "CAN Discarded Rx Full Queue");
  print_field<std::optional<uint32_t>>(oss, tx_drop,
                                       "CAN Discarded Tx Full Queue");
  print_field<std::optional<uint32_t>>(oss, tx_timeout, "CAN Transmit Timeout");
  print_field<std::optional<uint32_t>>(oss, bus_error, "Number of Bus Errors");
  print_field<std::optional<uint32_t>>(oss, error_warning,
                                       "Changes to Error Warning State");
  print_field<std::optional<uint32_t>>(oss, error_passive,
                                       "Changes to Error Passive State");
  print_field<std::optional<uint32_t>>(oss, bus_off,
                                       "Changes to Bus Off State");
  print_field<std::optional<uint32_t>>(oss, arbitration_lost,
                                       "Arbitration Lost Errors");
  print_field<std::optional<uint32_t>>(oss, restarts,
                                       "CAN Controller Restarts");

  if (oss.str().empty()) {
    oss << "No diagnostic information available." << std::endl;
  }

  return oss.str();
}

std::ostream &operator<<(std::ostream &os,
                         const CanDiagnostics &diag) noexcept {
  return os << diag.to_string();
}
