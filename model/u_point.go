package model

import (
	"github.com/lingfliu/ucs_core/model/meta"
)

type UPoint struct {
	Id       int64
	NodeId   int64
	Name     string
	Desc     string
	Addr     string
	Offset   int
	Rw       int // 1: read, 2: write, 3: R & W
	RMode    int //0: auto, 1: trig, 2: poll
	WMode    int //0: IO, 2: func
	PropSet  map[string]string
	DataMeta meta.DataMeta
	Data     []byte
}