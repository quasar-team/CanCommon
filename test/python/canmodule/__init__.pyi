from __future__ import annotations
import typing
from . import CanFlags

__all__ = [
    "CAN_INVALID_BITRATE",
    "CAN_LOST_ARBITRATION",
    "CAN_NACK",
    "CAN_TX_BUFFER_OVERFLOW",
    "CAN_TX_ERROR",
    "CanDevice",
    "CanDeviceArguments",
    "CanDeviceConfiguration",
    "CanDiagnostics",
    "CanFlags",
    "CanFrame",
    "CanReturnCode",
    "INTERNAL_API_ERROR",
    "NOT_CONNECTED",
    "SOCKET_ERROR",
    "SUCCESS",
    "TIMEOUT",
    "TOO_MANY_CONNECTIONS",
    "UNACKNOWLEDMENT",
    "UNKNOWN_CLOSE_ERROR",
    "UNKNOWN_OPEN_ERROR",
    "UNKNOWN_SEND_ERROR",
]

class CanDevice:
    @staticmethod
    def create(arg0: str, arg1: CanDeviceArguments) -> CanDevice: ...
    def args(self) -> CanDeviceArguments: ...
    def close(self) -> CanReturnCode: ...
    def diagnostics(self) -> CanDiagnostics: ...
    def open(self) -> CanReturnCode: ...
    @typing.overload
    def send(self, arg0: CanFrame) -> CanReturnCode: ...
    @typing.overload
    def send(self, arg0: list[CanFrame]) -> list[CanReturnCode]: ...

class CanDeviceArguments:
    def __init__(
        self,
        config: CanDeviceConfiguration,
        receiver: typing.Callable[[CanFrame], None],
    ) -> None: ...
    @property
    def config(self) -> CanDeviceConfiguration: ...

class CanDeviceConfiguration:
    bitrate: int | None
    bus_name: str | None
    bus_number: int | None
    enable_termination: bool | None
    host: str | None
    sent_acknowledgement: int | None
    timeout: int | None
    def __init__(self) -> None: ...
    def __str__(self) -> str: ...

class CanDiagnostics:
    def __init__(self) -> None: ...
    @property
    def arbitration_lost(self) -> int | None: ...
    @property
    def bitrate(self) -> int | None: ...
    @property
    def bus_error(self) -> int | None: ...
    @property
    def bus_off(self) -> int | None: ...
    @property
    def connected_clients_addresses(self) -> list[str] | None: ...
    @property
    def connected_clients_ports(self) -> list[int] | None: ...
    @property
    def connected_clients_timestamps(self) -> list[str] | None: ...
    @property
    def error_passive(self) -> int | None: ...
    @property
    def error_warning(self) -> int | None: ...
    @property
    def handle(self) -> int | None: ...
    @property
    def log_entries(self) -> list[str] | None: ...
    @property
    def mode(self) -> str | None: ...
    @property
    def name(self) -> str | None: ...
    @property
    def number_connected_clients(self) -> int | None: ...
    @property
    def restarts(self) -> int | None: ...
    @property
    def rx(self) -> int | None: ...
    @property
    def rx_drop(self) -> int | None: ...
    @property
    def rx_error(self) -> int | None: ...
    @property
    def state(self) -> str | None: ...
    @property
    def tcp_rx(self) -> int | None: ...
    @property
    def tcp_tx(self) -> int | None: ...
    @property
    def temperature(self) -> float | None: ...
    @property
    def tx(self) -> int | None: ...
    @property
    def tx_drop(self) -> int | None: ...
    @property
    def tx_error(self) -> int | None: ...
    @property
    def tx_timeout(self) -> int | None: ...
    @property
    def uptime(self) -> int | None: ...

class CanFrame:
    @typing.overload
    def __init__(self, id: int, requested_length: int, flags: int) -> None: ...
    @typing.overload
    def __init__(self, id: int, requested_length: int) -> None: ...
    @typing.overload
    def __init__(self, id: int) -> None: ...
    @typing.overload
    def __init__(self, id: int, message: list[str]) -> None: ...
    @typing.overload
    def __init__(self, id: int, message: list[str], flags: int) -> None: ...
    def __str__(self) -> str: ...
    def flags(self) -> int: ...
    def id(self) -> int: ...
    def is_error(self) -> bool: ...
    def is_extended_id(self) -> bool: ...
    def is_remote_request(self) -> bool: ...
    def is_standard_id(self) -> bool: ...
    def length(self) -> int: ...
    def message(self) -> list[str]: ...

class CanReturnCode:
    """
    Members:

      SUCCESS

      UNKNOWN_OPEN_ERROR

      SOCKET_ERROR

      TOO_MANY_CONNECTIONS

      TIMEOUT

      NOT_CONNECTED

      UNACKNOWLEDMENT

      INTERNAL_API_ERROR

      UNKNOWN_SEND_ERROR

      CAN_NACK

      CAN_TX_ERROR

      CAN_TX_BUFFER_OVERFLOW

      CAN_LOST_ARBITRATION

      CAN_INVALID_BITRATE

      UNKNOWN_CLOSE_ERROR
    """

    CAN_INVALID_BITRATE: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.CAN_INVALID_BITRATE: 13>
    CAN_LOST_ARBITRATION: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.CAN_LOST_ARBITRATION: 12>
    CAN_NACK: typing.ClassVar[CanReturnCode]  # value = <CanReturnCode.CAN_NACK: 9>
    CAN_TX_BUFFER_OVERFLOW: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.CAN_TX_BUFFER_OVERFLOW: 11>
    CAN_TX_ERROR: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.CAN_TX_ERROR: 10>
    INTERNAL_API_ERROR: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.INTERNAL_API_ERROR: 7>
    NOT_CONNECTED: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.NOT_CONNECTED: 5>
    SOCKET_ERROR: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.SOCKET_ERROR: 2>
    SUCCESS: typing.ClassVar[CanReturnCode]  # value = <CanReturnCode.SUCCESS: 0>
    TIMEOUT: typing.ClassVar[CanReturnCode]  # value = <CanReturnCode.TIMEOUT: 4>
    TOO_MANY_CONNECTIONS: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.TOO_MANY_CONNECTIONS: 3>
    UNACKNOWLEDMENT: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.UNACKNOWLEDMENT: 6>
    UNKNOWN_CLOSE_ERROR: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.UNKNOWN_CLOSE_ERROR: 14>
    UNKNOWN_OPEN_ERROR: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.UNKNOWN_OPEN_ERROR: 1>
    UNKNOWN_SEND_ERROR: typing.ClassVar[
        CanReturnCode
    ]  # value = <CanReturnCode.UNKNOWN_SEND_ERROR: 8>
    __members__: typing.ClassVar[
        dict[str, CanReturnCode]
    ]  # value = {'SUCCESS': <CanReturnCode.SUCCESS: 0>, 'UNKNOWN_OPEN_ERROR': <CanReturnCode.UNKNOWN_OPEN_ERROR: 1>, 'SOCKET_ERROR': <CanReturnCode.SOCKET_ERROR: 2>, 'TOO_MANY_CONNECTIONS': <CanReturnCode.TOO_MANY_CONNECTIONS: 3>, 'TIMEOUT': <CanReturnCode.TIMEOUT: 4>, 'NOT_CONNECTED': <CanReturnCode.NOT_CONNECTED: 5>, 'UNACKNOWLEDMENT': <CanReturnCode.UNACKNOWLEDMENT: 6>, 'INTERNAL_API_ERROR': <CanReturnCode.INTERNAL_API_ERROR: 7>, 'UNKNOWN_SEND_ERROR': <CanReturnCode.UNKNOWN_SEND_ERROR: 8>, 'CAN_NACK': <CanReturnCode.CAN_NACK: 9>, 'CAN_TX_ERROR': <CanReturnCode.CAN_TX_ERROR: 10>, 'CAN_TX_BUFFER_OVERFLOW': <CanReturnCode.CAN_TX_BUFFER_OVERFLOW: 11>, 'CAN_LOST_ARBITRATION': <CanReturnCode.CAN_LOST_ARBITRATION: 12>, 'CAN_INVALID_BITRATE': <CanReturnCode.CAN_INVALID_BITRATE: 13>, 'UNKNOWN_CLOSE_ERROR': <CanReturnCode.UNKNOWN_CLOSE_ERROR: 14>}
    def __eq__(self, other: typing.Any) -> bool: ...
    def __getstate__(self) -> int: ...
    def __hash__(self) -> int: ...
    def __index__(self) -> int: ...
    def __init__(self, value: int) -> None: ...
    def __int__(self) -> int: ...
    def __ne__(self, other: typing.Any) -> bool: ...
    def __repr__(self) -> str: ...
    def __setstate__(self, state: int) -> None: ...
    def __str__(self) -> str: ...
    @property
    def name(self) -> str: ...
    @property
    def value(self) -> int: ...

CAN_INVALID_BITRATE: CanReturnCode  # value = <CanReturnCode.CAN_INVALID_BITRATE: 13>
CAN_LOST_ARBITRATION: CanReturnCode  # value = <CanReturnCode.CAN_LOST_ARBITRATION: 12>
CAN_NACK: CanReturnCode  # value = <CanReturnCode.CAN_NACK: 9>
CAN_TX_BUFFER_OVERFLOW: (
    CanReturnCode  # value = <CanReturnCode.CAN_TX_BUFFER_OVERFLOW: 11>
)
CAN_TX_ERROR: CanReturnCode  # value = <CanReturnCode.CAN_TX_ERROR: 10>
INTERNAL_API_ERROR: CanReturnCode  # value = <CanReturnCode.INTERNAL_API_ERROR: 7>
NOT_CONNECTED: CanReturnCode  # value = <CanReturnCode.NOT_CONNECTED: 5>
SOCKET_ERROR: CanReturnCode  # value = <CanReturnCode.SOCKET_ERROR: 2>
SUCCESS: CanReturnCode  # value = <CanReturnCode.SUCCESS: 0>
TIMEOUT: CanReturnCode  # value = <CanReturnCode.TIMEOUT: 4>
TOO_MANY_CONNECTIONS: CanReturnCode  # value = <CanReturnCode.TOO_MANY_CONNECTIONS: 3>
UNACKNOWLEDMENT: CanReturnCode  # value = <CanReturnCode.UNACKNOWLEDMENT: 6>
UNKNOWN_CLOSE_ERROR: CanReturnCode  # value = <CanReturnCode.UNKNOWN_CLOSE_ERROR: 14>
UNKNOWN_OPEN_ERROR: CanReturnCode  # value = <CanReturnCode.UNKNOWN_OPEN_ERROR: 1>
UNKNOWN_SEND_ERROR: CanReturnCode  # value = <CanReturnCode.UNKNOWN_SEND_ERROR: 8>
