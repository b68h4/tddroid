#!/bin/sh

DEST=tdweb/src/prebuilt/release/
mkdir -p $DEST || exit 1
cp build/wasm/td_wasm.js build/wasm/td_wasm.wasm $DEST || exit 1
cp build/asmjs/td_asmjs.js build/asmjs/td_asmjs.js.mem $DEST || exit 1
