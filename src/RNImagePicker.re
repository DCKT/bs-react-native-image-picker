[@bs.deriving abstract]
type customButton = {
  title: string,
  name: string,
};

[@bs.deriving abstract]
type storageOptions = {
  [@bs.optional]
  skipBackup: bool,
  [@bs.optional]
  path: string,
  [@bs.optional]
  cameraRoll: bool,
  [@bs.optional]
  waitUntilSaved: bool,
};

[@bs.deriving abstract]
type permissionDenied = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  text: string,
  [@bs.optional]
  reTryTitle: string,
  [@bs.optional]
  okTitle: string,
};

[@bs.deriving jsConverter]
type mediaType = [ | `low | `medium | `high];

[@bs.deriving jsConverter]
type videoQuality = [ | `low | `medium | `high];

[@bs.deriving jsConverter]
type cameraType = [ | `front | `back];

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  cancelButtonTitle: string,
  [@bs.optional]
  takePhotoButtonTitle: string,
  [@bs.optional]
  chooseFromLibraryButtonTitle: string,
  [@bs.optional]
  customButtons: array(customButton),
  [@bs.optional]
  cameraType,
  [@bs.optional]
  mediaType,
  [@bs.optional]
  maxWidth: float,
  [@bs.optional]
  maxHeight: float,
  [@bs.optional]
  quality: float,
  [@bs.optional]
  videoQuality,
  [@bs.optional]
  durationLimit: float,
  [@bs.optional]
  rotation: float,
  [@bs.optional]
  allowsEditing: bool,
  [@bs.optional]
  noData: bool,
  [@bs.optional]
  storageOptions,
  [@bs.optional]
  permissionDenied,
};

[@bs.deriving abstract]
type response = {
  didCancel: bool,
  error: Js.Nullable.t(Js.Exn.t),
  customButton: string,
  data: string,
  uri: string,
  origURL: string,
  isVertical: bool,
  width: float,
  height: float,
  fileSize: float,
  [@bs.as "type"]
  fileType: string,
  fileName: string,
  path: string,
  latitude: float,
  longitude: float,
  timestamp: float,
  originalRotation: float,
};

[@bs.deriving abstract]
type callback = response => unit;

[@bs.module "react-native-image-picker"]
external showImagePicker: (options, callback) => unit = "showImagePicker";

[@bs.module "react-native-image-picker"]
external launchCamera: (options, callback) => unit = "launchCamera";

[@bs.module "react-native-image-picker"]
external launchImageLibrary: (options, callback) => unit =
  "launchImageLibrary";