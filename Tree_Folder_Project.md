# Cây thư mục chính (cấu trúc của một Yocto Project khi clone về, ở đây là AGL build trên nền Yocto Poky):
```
.
├── bsp
│   ├── meta-agl-refhw
│   ├── meta-arm
│   ├── meta-aws
│   ├── meta-freescale
│   ├── meta-freescale-3rdparty
│   ├── meta-raspberrypi
│   ├── meta-rcar
│   ├── meta-renesas
│   ├── meta-rtlwifi
│   ├── meta-sancloud
│   ├── meta-sifive
│   └── meta-ti
├── external
│   ├── meta-clang
│   ├── meta-codechecker
│   ├── meta-flutter
│   ├── meta-lts-mixins_rust
│   ├── meta-openembedded
│   ├── meta-qt5
│   ├── meta-security
│   ├── meta-selinux
│   ├── meta-spdxscanner
│   ├── meta-tensorflow
│   ├── meta-virtualization
│   ├── poky
│   └── workspace-automation
├── meta-agl
│   ├── agl-layers-overview.md
│   ├── docs
│   ├── LICENSE
│   ├── LICENSE.GPL-2.0-only
│   ├── LICENSE.MIT
│   ├── meta-agl-bsp
│   ├── meta-agl-core
│   ├── meta-agl-ic
│   ├── meta-agl-ivi
│   ├── meta-agl.md
│   ├── meta-app-framework
│   ├── meta-netboot
│   ├── meta-pipewire
│   ├── README-AGL.md
│   ├── README.md -> meta-agl.md
│   ├── scripts
│   └── templates
├── meta-agl-demo
│   ├── classes
│   ├── conf
│   ├── LICENSE
│   ├── LICENSE.GPL-2.0-only
│   ├── LICENSE.MIT
│   ├── meta-agl-demo.md
│   ├── meta-agl-kvm-demo
│   ├── README -> README.md
│   ├── README.md -> meta-agl-demo.md
│   ├── recipes-config
│   ├── recipes-connectivity
│   ├── recipes-core
│   ├── recipes-demo
│   ├── recipes-devtools
│   ├── recipes-graphics
│   ├── recipes-kernel
│   ├── recipes-multimedia
│   ├── recipes-navigation
│   ├── recipes-platform
│   ├── recipes-qt
│   ├── recipes-support
│   ├── recipes-wam
│   ├── scripts
│   └── templates
├── meta-agl-devel
│   ├── docs
│   ├── LICENSE
│   ├── LICENSE.GPL-2.0-only
│   ├── LICENSE.MIT
│   ├── meta-agl-devel.md
│   ├── meta-agl-drm-lease
│   ├── meta-agl-flutter
│   ├── meta-agl-ic-container
│   ├── meta-agl-jailhouse
│   ├── meta-agl-rdp
│   ├── meta-agl-test
│   ├── meta-agl-wireless-monitor
│   ├── meta-egvirt
│   ├── meta-oem-production-readiness
│   ├── meta-offline-voice-agent
│   ├── meta-uhmi
│   ├── README.md -> meta-agl-devel.md
│   └── templates
├── meta-canutils
│   ├── conf
│   ├── COPYING.MIT
│   ├── README
│   ├── recipes-connectivity
│   └── recipes-example
├── meta-custom-hdmi-display
│   ├── conf
│   ├── COPYING.MIT
│   ├── README
│   └── recipes-example
├── meta-ducanh-devlinux
│   ├── conf
│   ├── COPYING.MIT
│   ├── README
│   ├── recipes-apps
│   └── recipes-example
└── raspberrypi4
    ├── agl-init-build-env
    ├── aglsetup.manifest
    ├── bitbake-cookerdaemon.log
    ├── cache
    ├── conf
    ├── downloads
    ├── sstate-cache
    ├── tmp
    └── workspace
```
---
# Cây thư mục image:

+ /media/admin1/SSD-480GB/AGL2204/AGL/quillback là đường dẫn tới folder yoto project. 

```
/media/admin1/SSD-480GB/AGL2204/AGL/quillback$ ls
bsp  external  meta-agl  meta-agl-demo  meta-agl-devel  meta-canutils  meta-custom-hdmi-display  meta-ducanh-devlinux  raspberrypi4
/media/admin1/SSD-480GB/AGL2204/AGL/quillback$ cd raspberrypi4/tmp/deploy/images/raspberrypi4-64/
/media/admin1/SSD-480GB/AGL2204/AGL/quillback/raspberrypi4/tmp/deploy/images/raspberrypi4-64$ tree -L 2
.
├── agl-ivi-image.env
├── agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.manifest
├── agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.wic.bmap
├── agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.wic.xz
├── agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.wic.xz.sha256sum
├── agl-ivi-image-raspberrypi4-64-20251217175814.testdata.json
├── agl-ivi-image-raspberrypi4-64.manifest -> agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.manifest
├── agl-ivi-image-raspberrypi4-64.testdata.json -> agl-ivi-image-raspberrypi4-64-20251217175814.testdata.json
├── agl-ivi-image-raspberrypi4-64.wic.bmap -> agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.wic.bmap
├── agl-ivi-image-raspberrypi4-64.wic.xz -> agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.wic.xz
├── agl-ivi-image-raspberrypi4-64.wic.xz.sha256sum -> agl-ivi-image-raspberrypi4-64-20251217175814.rootfs.wic.xz.sha256sum
├── at86rf233-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtbo
├── at86rf233.dtbo -> at86rf233-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtbo
├── at86rf233-raspberrypi4-64.dtbo -> at86rf233-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtbo
├── bcm2711-rpi-400-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-400.dtb -> bcm2711-rpi-400-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-400-raspberrypi4-64.dtb -> bcm2711-rpi-400-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-4-b-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-4-b.dtb -> bcm2711-rpi-4-b-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-4-b-raspberrypi4-64.dtb -> bcm2711-rpi-4-b-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-4-b+vc4.dtb
├── bcm2711-rpi-4-b+vc4+ft5406.dtb
├── bcm2711-rpi-cm4-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-cm4.dtb -> bcm2711-rpi-cm4-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb
├── bcm2711-rpi-cm4-raspberrypi4-64.dtb -> bcm2711-rpi-cm4-1-5.15.92+git0+509f4b9d68_14b35093ca-r0-raspberrypi4-64-20251021043236.dtb

```

# Cây thư mục trong kernel:
```
/media/admin1/SSD-480GB/AGL2204/AGL/quillback/raspberrypi4/workspace/sources/linux-raspberrypi$ tree -L 2
.
├── arch
│   ├── alpha
│   ├── arc
│   ├── arm
│   ├── arm64
│   ├── csky
│   ├── h8300
│   ├── hexagon
│   ├── ia64
│   ├── Kconfig
│   ├── m68k
│   ├── microblaze
│   ├── mips
│   ├── nds32
│   ├── nios2
│   ├── openrisc
│   ├── parisc
│   ├── powerpc
│   ├── riscv
│   ├── s390
│   ├── sh
│   ├── sparc
│   ├── um
│   ├── x86
│   └── xtensa
├── block
│   ├── badblocks.c
│   ├── bdev.c
│   ├── bfq-cgroup.c
│   ├── bfq-iosched.c
│   ├── bfq-iosched.h
│   ├── bfq-wf2q.c
│   ├── bio.c
│   ├── bio-integrity.c
│   ├── blk-cgroup.c
│   ├── blk-cgroup-rwstat.c
│   ├── blk-cgroup-rwstat.h
│   ├── blk-core.c
│   ├── blk-crypto.c
│   ├── blk-crypto-fallback.c
│   ├── blk-crypto-internal.h
│   ├── blk-exec.c
│   ├── blk-flush.c
│   ├── blk.h
│   ├── blk-integrity.c
│   ├── blk-ioc.c
│   ├── blk-iocost.c
│   ├── blk-iolatency.c
│   ├── blk-ioprio.c
│   ├── blk-ioprio.h
│   ├── blk-lib.c
│   ├── blk-map.c
│   ├── blk-merge.c
│   ├── blk-mq.c
│   ├── blk-mq-cpumap.c
│   ├── blk-mq-debugfs.c
│   ├── blk-mq-debugfs.h
│   ├── blk-mq-debugfs-zoned.c
│   ├── blk-mq.h
│   ├── blk-mq-pci.c
│   ├── blk-mq-rdma.c
│   ├── blk-mq-sched.c
│   ├── blk-mq-sched.h
│   ├── blk-mq-sysfs.c
│   ├── blk-mq-tag.c
│   ├── blk-mq-tag.h
│   ├── blk-mq-virtio.c
│   ├── blk-pm.c
│   ├── blk-pm.h
│   ├── blk-rq-qos.c
│   ├── blk-rq-qos.h
│   ├── blk-settings.c
│   ├── blk-stat.c
│   ├── blk-stat.h
│   ├── blk-sysfs.c
│   ├── blk-throttle.c
│   ├── blk-timeout.c
│   ├── blk-wbt.c
│   ├── blk-wbt.h
│   ├── blk-zoned.c
│   ├── bounce.c
│   ├── bsg.c
│   ├── bsg-lib.c
│   ├── disk-events.c
│   ├── elevator.c
│   ├── fops.c
│   ├── genhd.c
│   ├── holder.c
│   ├── ioctl.c
│   ├── ioprio.c
│   ├── Kconfig
│   ├── Kconfig.iosched
│   ├── keyslot-manager.c
│   ├── kyber-iosched.c
│   ├── Makefile
│   ├── mq-deadline.c
│   ├── opal_proto.h
│   ├── partitions
│   ├── sed-opal.c
│   └── t10-pi.c
├── certs
│   ├── blacklist.c
│   ├── blacklist.h
│   ├── blacklist_hashes.c
│   ├── blacklist_nohashes.c
│   ├── common.c
│   ├── common.h
│   ├── Kconfig
│   ├── Makefile
│   ├── revocation_certificates.S
│   ├── system_certificates.S
│   └── system_keyring.c
├── COPYING
├── CREDITS
├── crypto
│   ├── 842.c
│   ├── acompress.c
│   ├── adiantum.c
│   ├── aead.c
│   ├── aegis128-core.c
│   ├── aegis128-neon.c
│   ├── aegis128-neon-inner.c
│   ├── aegis.h
│   ├── aes_generic.c
│   ├── aes_ti.c
│   ├── af_alg.c
│   ├── ahash.c
│   ├── akcipher.c
│   ├── algapi.c
│   ├── algboss.c
│   ├── algif_aead.c
│   ├── algif_hash.c
│   ├── algif_rng.c
│   ├── algif_skcipher.c
│   ├── ansi_cprng.c
│   ├── anubis.c
│   ├── api.c
│   ├── arc4.c
│   ├── asymmetric_keys
│   ├── async_tx
│   ├── authenc.c
│   ├── authencesn.c
│   ├── blake2b_generic.c
│   ├── blowfish_common.c
│   ├── blowfish_generic.c
│   ├── camellia_generic.c
│   ├── cast5_generic.c
│   ├── cast6_generic.c
│   ├── cast_common.c
│   ├── cbc.c
│   ├── ccm.c
│   ├── cfb.c
│   ├── chacha20poly1305.c
│   ├── chacha_generic.c
│   ├── cipher.c
│   ├── cmac.c
│   ├── compress.c
│   ├── crc32c_generic.c
│   ├── crc32_generic.c
│   ├── crct10dif_common.c
│   ├── crct10dif_generic.c
│   ├── cryptd.c
│   ├── crypto_engine.c
│   ├── crypto_null.c
│   ├── crypto_user_base.c
│   ├── crypto_user_stat.c
│   ├── ctr.c
│   ├── cts.c
│   ├── curve25519-generic.c
│   ├── deflate.c
│   ├── des_generic.c
│   ├── dh.c
│   ├── dh_helper.c
│   ├── drbg.c
│   ├── ecb.c
│   ├── ecc.c
│   ├── ecc_curve_defs.h
│   ├── ecc.h
│   ├── ecdh.c
│   ├── ecdh_helper.c
│   ├── ecdsa.c
│   ├── ecdsasignature.asn1
│   ├── echainiv.c
│   ├── ecrdsa.c
│   ├── ecrdsa_defs.h
│   ├── ecrdsa_params.asn1
│   ├── ecrdsa_pub_key.asn1
│   ├── essiv.c
│   ├── fcrypt.c
│   ├── fips.c
│   ├── gcm.c
│   ├── geniv.c
│   ├── gf128mul.c
│   ├── ghash-generic.c
│   ├── hash_info.c
│   ├── hmac.c
│   ├── internal.h
│   ├── jitterentropy.c
│   ├── jitterentropy.h
│   ├── jitterentropy-kcapi.c
│   ├── Kconfig
│   ├── keywrap.c
│   ├── khazad.c
│   ├── kpp.c
│   ├── lrw.c
│   ├── lz4.c
│   ├── lz4hc.c
│   ├── lzo.c
│   ├── lzo-rle.c
│   ├── Makefile
│   ├── md4.c
│   ├── md5.c
│   ├── michael_mic.c
│   ├── nhpoly1305.c
│   ├── ofb.c
│   ├── pcbc.c
│   ├── pcrypt.c
│   ├── poly1305_generic.c
│   ├── proc.c
│   ├── ripemd.h
│   ├── rmd160.c
│   ├── rng.c
│   ├── rsa.c
│   ├── rsa_helper.c
│   ├── rsa-pkcs1pad.c
│   ├── rsaprivkey.asn1
│   ├── rsapubkey.asn1
│   ├── scatterwalk.c
│   ├── scompress.c
│   ├── seed.c
│   ├── seqiv.c
│   ├── serpent_generic.c
│   ├── sha1_generic.c
│   ├── sha256_generic.c
│   ├── sha3_generic.c
│   ├── sha512_generic.c
│   ├── shash.c
│   ├── simd.c
│   ├── skcipher.c
│   ├── sm2.c
│   ├── sm2signature.asn1
│   ├── sm3_generic.c
│   ├── sm4_generic.c
│   ├── streebog_generic.c
│   ├── tcrypt.c
│   ├── tcrypt.h
│   ├── tea.c
│   ├── testmgr.c
│   ├── testmgr.h
│   ├── twofish_common.c
│   ├── twofish_generic.c
│   ├── vmac.c
│   ├── wp512.c
│   ├── xcbc.c
│   ├── xor.c
│   ├── xts.c
│   ├── xxhash_generic.c
│   └── zstd.c
├── Documentation
│   ├── ABI
│   ├── accounting
│   ├── admin-guide
│   ├── arch.rst
│   ├── arm
│   ├── arm64
│   ├── asm-annotations.rst
│   ├── atomic_bitops.txt
│   ├── atomic_t.txt
│   ├── block
│   ├── bpf
│   ├── cdrom
│   ├── Changes -> process/changes.rst
│   ├── CodingStyle
│   ├── conf.py
│   ├── COPYING-logo
│   ├── core-api
│   ├── cpu-freq
│   ├── crypto
│   ├── devicetree
│   ├── dev-tools
│   ├── doc-guide
│   ├── docutils.conf
│   ├── dontdiff
│   ├── driver-api
│   ├── fault-injection
│   ├── fb
│   ├── features
│   ├── filesystems
│   ├── firmware_class
│   ├── firmware-guide
│   ├── fpga
│   ├── gpu
│   ├── hid
│   ├── hwmon
│   ├── i2c
│   ├── ia64
│   ├── ide
│   ├── iio
│   ├── index.rst
│   ├── infiniband
│   ├── input
│   ├── isdn
│   ├── kbuild
│   ├── Kconfig
│   ├── kernel-hacking
│   ├── leds
│   ├── litmus-tests
│   ├── livepatch
│   ├── locking
│   ├── logo.gif
│   ├── m68k
│   ├── maintainer
│   ├── Makefile
│   ├── memory-barriers.txt
│   ├── mhi
│   ├── mips
│   ├── misc-devices
│   ├── netlabel
│   ├── networking
│   ├── nios2
│   ├── nvdimm
│   ├── openrisc
│   ├── parisc
│   ├── PCI
│   ├── pcmcia
│   ├── power
│   ├── powerpc
│   ├── process
│   ├── RCU
│   ├── riscv
│   ├── s390
│   ├── scheduler
│   ├── scsi
│   ├── security
│   ├── sh
│   ├── sound
│   ├── sparc
│   ├── sphinx
│   ├── sphinx-static
│   ├── spi
│   ├── staging
│   ├── SubmittingPatches
│   ├── target
│   ├── timers
│   ├── trace
│   ├── translations
│   ├── tty
│   ├── usb
│   ├── userspace-api
│   ├── virt
│   ├── vm
│   ├── w1
│   ├── watchdog
│   ├── watch_queue.rst
│   ├── x86
│   └── xtensa
├── drivers
│   ├── accessibility
│   ├── acpi
│   ├── amba
│   ├── android
│   ├── ata
│   ├── atm
│   ├── auxdisplay
│   ├── base
│   ├── bcma
│   ├── block
│   ├── bluetooth
│   ├── bus
│   ├── cdrom
│   ├── char
│   ├── clk
│   ├── clocksource
│   ├── comedi
│   ├── connector
│   ├── counter
│   ├── cpufreq
│   ├── cpuidle
│   ├── crypto
│   ├── cxl
│   ├── dax
│   ├── dca
│   ├── devfreq
│   ├── dio
│   ├── dma
│   ├── dma-buf
│   ├── edac
│   ├── eisa
│   ├── extcon
│   ├── firewire
│   ├── firmware
│   ├── fpga
│   ├── fsi
│   ├── gnss
│   ├── gpio
│   ├── gpu
│   ├── greybus
│   ├── hid
│   ├── hsi
│   ├── hv
│   ├── hwmon
│   ├── hwspinlock
│   ├── hwtracing
│   ├── i2c
│   ├── i3c
│   ├── idle
│   ├── iio
│   ├── infiniband
│   ├── input
│   ├── interconnect
│   ├── iommu
│   ├── ipack
│   ├── irqchip
│   ├── isdn
│   ├── Kconfig
│   ├── leds
│   ├── macintosh
│   ├── mailbox
│   ├── Makefile
│   ├── mcb
│   ├── md
│   ├── media
│   ├── memory
│   ├── memstick
│   ├── message
│   ├── mfd
│   ├── misc
│   ├── mmc
│   ├── most
│   ├── mtd
│   ├── mux
│   ├── net
│   ├── nfc
│   ├── ntb
│   ├── nubus
│   ├── nvdimm
│   ├── nvme
│   ├── nvmem
│   ├── of
│   ├── opp
│   ├── parisc
│   ├── parport
│   ├── pci
│   ├── pcmcia
│   ├── perf
│   ├── phy
│   ├── pinctrl
│   ├── platform
│   ├── pnp
│   ├── power
│   ├── powercap
│   ├── pps
│   ├── ps3
│   ├── ptp
│   ├── pwm
│   ├── rapidio
│   ├── ras
│   ├── regulator
│   ├── remoteproc
│   ├── reset
│   ├── rpmsg
│   ├── rtc
│   ├── s390
│   ├── sbus
│   ├── scsi
│   ├── sh
│   ├── siox
│   ├── slimbus
│   ├── soc
│   ├── soundwire
│   ├── spi
│   ├── spmi
│   ├── ssb
│   ├── staging
│   ├── target
│   ├── tc
│   ├── tee
│   ├── thermal
│   ├── thunderbolt
│   ├── tty
│   ├── uio
│   ├── usb
│   ├── vdpa
│   ├── vfio
│   ├── vhost
│   ├── video
│   ├── virt
│   ├── virtio
│   ├── visorbus
│   ├── vlynq
│   ├── vme
│   ├── w1
│   ├── watchdog
│   ├── xen
│   └── zorro
├── fs
│   ├── 9p
│   ├── adfs
│   ├── affs
│   ├── afs
│   ├── aio.c
│   ├── anon_inodes.c
│   ├── attr.c
│   ├── autofs
│   ├── bad_inode.c
│   ├── befs
│   ├── bfs
│   ├── binfmt_aout.c
│   ├── binfmt_elf.c
│   ├── binfmt_elf_fdpic.c
│   ├── binfmt_flat.c
│   ├── binfmt_misc.c
│   ├── binfmt_script.c
│   ├── btrfs
│   ├── buffer.c
│   ├── cachefiles
│   ├── ceph
│   ├── char_dev.c
│   ├── cifs
│   ├── coda
│   ├── compat_binfmt_elf.c
│   ├── configfs
│   ├── coredump.c
│   ├── cramfs
│   ├── crypto
│   ├── dax.c
│   ├── dcache.c
│   ├── debugfs
│   ├── devpts
│   ├── direct-io.c
│   ├── dlm
│   ├── d_path.c
│   ├── drop_caches.c
│   ├── ecryptfs
│   ├── efivarfs
│   ├── efs
│   ├── erofs
│   ├── eventfd.c
│   ├── eventpoll.c
│   ├── exec.c
│   ├── exfat
│   ├── exportfs
│   ├── ext2
│   ├── ext4
│   ├── f2fs
│   ├── fat
│   ├── fcntl.c
│   ├── fhandle.c
│   ├── file.c
│   ├── filesystems.c
│   ├── file_table.c
│   ├── freevxfs
│   ├── fscache
│   ├── fs_context.c
│   ├── fsopen.c
│   ├── fs_parser.c
│   ├── fs_pin.c
│   ├── fs_struct.c
│   ├── fs_types.c
│   ├── fs-writeback.c
│   ├── fuse
│   ├── gfs2
│   ├── hfs
│   ├── hfsplus
│   ├── hostfs
│   ├── hpfs
│   ├── hugetlbfs
│   ├── init.c
│   ├── inode.c
│   ├── internal.h
│   ├── ioctl.c
│   ├── iomap
│   ├── isofs
│   ├── jbd2
│   ├── jffs2
│   ├── jfs
│   ├── Kconfig
│   ├── Kconfig.binfmt
│   ├── kernel_read_file.c
│   ├── kernfs
│   ├── ksmbd
│   ├── libfs.c
│   ├── lockd
│   ├── locks.c
│   ├── Makefile
│   ├── mbcache.c
│   ├── minix
│   ├── mount.h
│   ├── mpage.c
│   ├── namei.c
│   ├── namespace.c
│   ├── netfs
│   ├── nfs
│   ├── nfs_common
│   ├── nfsd
│   ├── nilfs2
│   ├── nls
│   ├── no-block.c
│   ├── notify
│   ├── nsfs.c
│   ├── ntfs
│   ├── ntfs3
│   ├── ocfs2
│   ├── omfs
│   ├── open.c
│   ├── openpromfs
│   ├── orangefs
│   ├── overlayfs
│   ├── pipe.c
│   ├── pnode.c
│   ├── pnode.h
│   ├── posix_acl.c
│   ├── proc
│   ├── proc_namespace.c
│   ├── pstore
│   ├── qnx4
│   ├── qnx6
│   ├── quota
│   ├── ramfs
│   ├── readdir.c
│   ├── read_write.c
│   ├── reiserfs
│   ├── remap_range.c
│   ├── romfs
│   ├── select.c
│   ├── seq_file.c
│   ├── signalfd.c
│   ├── smbfs_common
│   ├── splice.c
│   ├── squashfs
│   ├── stack.c
│   ├── stat.c
│   ├── statfs.c
│   ├── super.c
│   ├── sync.c
│   ├── sysfs
│   ├── sysv
│   ├── timerfd.c
│   ├── tracefs
│   ├── ubifs
│   ├── udf
│   ├── ufs
│   ├── unicode
│   ├── userfaultfd.c
│   ├── utimes.c
│   ├── vboxsf
│   ├── verity
│   ├── xattr.c
│   ├── xfs
│   └── zonefs
├── include
│   ├── acpi
│   ├── asm-generic
│   ├── clocksource
│   ├── crypto
│   ├── drm
│   ├── dt-bindings
│   ├── keys
│   ├── kunit
│   ├── kvm
│   ├── linux
│   ├── math-emu
│   ├── media
│   ├── memory
│   ├── misc
│   ├── net
│   ├── pcmcia
│   ├── ras
│   ├── rdma
│   ├── scsi
│   ├── soc
│   ├── sound
│   ├── target
│   ├── trace
│   ├── uapi
│   ├── vdso
│   ├── video
│   └── xen
├── init
│   ├── calibrate.c
│   ├── do_mounts.c
│   ├── do_mounts.h
│   ├── do_mounts_initrd.c
│   ├── do_mounts_rd.c
│   ├── initramfs.c
│   ├── init_task.c
│   ├── Kconfig
│   ├── main.c
│   ├── Makefile
│   ├── noinitramfs.c
│   └── version.c
├── io_uring
│   ├── io_uring.c
│   ├── io-wq.c
│   ├── io-wq.h
│   └── Makefile
├── ipc
│   ├── compat.c
│   ├── ipc_sysctl.c
│   ├── Makefile
│   ├── mq_sysctl.c
│   ├── mqueue.c
│   ├── msg.c
│   ├── msgutil.c
│   ├── namespace.c
│   ├── sem.c
│   ├── shm.c
│   ├── syscall.c
│   ├── util.c
│   └── util.h
├── Kbuild
├── Kconfig
├── kernel
│   ├── acct.c
│   ├── async.c
│   ├── audit.c
│   ├── auditfilter.c
│   ├── audit_fsnotify.c
│   ├── audit.h
│   ├── auditsc.c
│   ├── audit_tree.c
│   ├── audit_watch.c
│   ├── backtracetest.c
│   ├── bounds.c
│   ├── bpf
│   ├── capability.c
│   ├── cfi.c
│   ├── cgroup
│   ├── compat.c
│   ├── configs
│   ├── configs.c
│   ├── context_tracking.c
│   ├── cpu.c
│   ├── cpu_pm.c
│   ├── crash_core.c
│   ├── crash_dump.c
│   ├── cred.c
│   ├── debug
│   ├── delayacct.c
│   ├── dma
│   ├── dma.c
│   ├── entry
│   ├── events
│   ├── exec_domain.c
│   ├── exit.c
│   ├── extable.c
│   ├── fail_function.c
│   ├── fork.c
│   ├── freezer.c
│   ├── futex
│   ├── gcov
│   ├── gen_kheaders.sh
│   ├── groups.c
│   ├── hung_task.c
│   ├── iomem.c
│   ├── irq
│   ├── irq_work.c
│   ├── jump_label.c
│   ├── kallsyms.c
│   ├── kcmp.c
│   ├── Kconfig.freezer
│   ├── Kconfig.hz
│   ├── Kconfig.locks
│   ├── Kconfig.preempt
│   ├── kcov.c
│   ├── kcsan
│   ├── kexec.c
│   ├── kexec_core.c
│   ├── kexec_elf.c
│   ├── kexec_file.c
│   ├── kexec_internal.h
│   ├── kheaders.c
│   ├── kmod.c
│   ├── kprobes.c
│   ├── ksysfs.c
│   ├── kthread.c
│   ├── latencytop.c
│   ├── livepatch
│   ├── locking
│   ├── Makefile
│   ├── module.c
│   ├── module-internal.h
│   ├── module_signature.c
│   ├── module_signing.c
│   ├── notifier.c
│   ├── nsproxy.c
│   ├── padata.c
│   ├── panic.c
│   ├── params.c
│   ├── pid.c
│   ├── pid_namespace.c
│   ├── power
│   ├── printk
│   ├── profile.c
│   ├── ptrace.c
│   ├── range.c
│   ├── rcu
│   ├── reboot.c
│   ├── regset.c
│   ├── relay.c
│   ├── resource.c
│   ├── resource_kunit.c
│   ├── rseq.c
│   ├── scftorture.c
│   ├── sched
│   ├── scs.c
│   ├── seccomp.c
│   ├── signal.c
│   ├── smpboot.c
│   ├── smpboot.h
│   ├── smp.c
│   ├── softirq.c
│   ├── stackleak.c
│   ├── stacktrace.c
│   ├── static_call.c
│   ├── static_call_inline.c
│   ├── stop_machine.c
│   ├── sys.c
│   ├── sysctl.c
│   ├── sysctl-test.c
│   ├── sys_ni.c
│   ├── taskstats.c
│   ├── task_work.c
│   ├── test_kprobes.c
│   ├── time
│   ├── torture.c
│   ├── trace
│   ├── tracepoint.c
│   ├── tsacct.c
│   ├── ucount.c
│   ├── uid16.c
│   ├── uid16.h
│   ├── umh.c
│   ├── up.c
│   ├── user.c
│   ├── usermode_driver.c
│   ├── user_namespace.c
│   ├── user-return-notifier.c
│   ├── utsname.c
│   ├── utsname_sysctl.c
│   ├── watchdog.c
│   ├── watchdog_hld.c
│   ├── watch_queue.c
│   ├── workqueue.c
│   └── workqueue_internal.h
├── lib
│   ├── 842
│   ├── argv_split.c
│   ├── ashldi3.c
│   ├── ashrdi3.c
│   ├── asn1_decoder.c
│   ├── asn1_encoder.c
│   ├── assoc_array.c
│   ├── atomic64.c
│   ├── atomic64_test.c
│   ├── audit.c
│   ├── bcd.c
│   ├── bch.c
│   ├── bitfield_kunit.c
│   ├── bitmap.c
│   ├── bitrev.c
│   ├── bootconfig.c
│   ├── bsearch.c
│   ├── btree.c
│   ├── bucket_locks.c
│   ├── bug.c
│   ├── buildid.c
│   ├── build_OID_registry
│   ├── bust_spinlocks.c
│   ├── check_signature.c
│   ├── checksum.c
│   ├── clz_ctz.c
│   ├── clz_tab.c
│   ├── cmdline.c
│   ├── cmdline_kunit.c
│   ├── cmpdi2.c
│   ├── compat_audit.c
│   ├── cpumask.c
│   ├── cpu_rmap.c
│   ├── crc16.c
│   ├── crc32.c
│   ├── crc32defs.h
│   ├── crc32test.c
│   ├── crc4.c
│   ├── crc64.c
│   ├── crc7.c
│   ├── crc8.c
│   ├── crc-ccitt.c
│   ├── crc-itu-t.c
│   ├── crc-t10dif.c
│   ├── crypto
│   ├── ctype.c
│   ├── debug_info.c
│   ├── debug_locks.c
│   ├── debugobjects.c
│   ├── dec_and_lock.c
│   ├── decompress_bunzip2.c
│   ├── decompress.c
│   ├── decompress_inflate.c
│   ├── decompress_unlz4.c
│   ├── decompress_unlzma.c
│   ├── decompress_unlzo.c
│   ├── decompress_unxz.c
│   ├── decompress_unzstd.c
│   ├── devmem_is_allowed.c
│   ├── devres.c
│   ├── digsig.c
│   ├── dim
│   ├── dump_stack.c
│   ├── dynamic_debug.c
│   ├── dynamic_queue_limits.c
│   ├── earlycpio.c
│   ├── errname.c
│   ├── error-inject.c
│   ├── errseq.c
│   ├── extable.c
│   ├── fault-inject.c
│   ├── fault-inject-usercopy.c
│   ├── fdt_addresses.c
│   ├── fdt.c
│   ├── fdt_empty_tree.c
│   ├── fdt_ro.c
│   ├── fdt_rw.c
│   ├── fdt_strerror.c
│   ├── fdt_sw.c
│   ├── fdt_wip.c
│   ├── find_bit_benchmark.c
│   ├── find_bit.c
│   ├── flex_proportions.c
│   ├── fonts
│   ├── genalloc.c
│   ├── gen_crc32table.c
│   ├── gen_crc64table.c
│   ├── generic-radix-tree.c
│   ├── glob.c
│   ├── globtest.c
│   ├── hexdump.c
│   ├── hweight.c
│   ├── idr.c
│   ├── inflate.c
│   ├── interval_tree.c
│   ├── interval_tree_test.c
│   ├── iomap.c
│   ├── iomap_copy.c
│   ├── iommu-helper.c
│   ├── iov_iter.c
│   ├── irq_poll.c
│   ├── irq_regs.c
│   ├── is_single_threaded.c
│   ├── kasprintf.c
│   ├── Kconfig
│   ├── Kconfig.debug
│   ├── Kconfig.kasan
│   ├── Kconfig.kcsan
│   ├── Kconfig.kfence
│   ├── Kconfig.kgdb
│   ├── Kconfig.ubsan
│   ├── kfifo.c
│   ├── klist.c
│   ├── kobject.c
│   ├── kobject_uevent.c
│   ├── kstrtox.c
│   ├── kstrtox.h
│   ├── kunit
│   ├── libcrc32c.c
│   ├── linear_ranges.c
│   ├── list_debug.c
│   ├── list_sort.c
│   ├── list-test.c
│   ├── livepatch
│   ├── llist.c
│   ├── locking-selftest.c
│   ├── locking-selftest-hardirq.h
│   ├── locking-selftest-mutex.h
│   ├── locking-selftest-rlock.h
│   ├── locking-selftest-rlock-hardirq.h
│   ├── locking-selftest-rlock-softirq.h
│   ├── locking-selftest-rsem.h
│   ├── locking-selftest-rtmutex.h
│   ├── locking-selftest-softirq.h
│   ├── locking-selftest-spin.h
│   ├── locking-selftest-spin-hardirq.h
│   ├── locking-selftest-spin-softirq.h
│   ├── locking-selftest-wlock.h
│   ├── locking-selftest-wlock-hardirq.h
│   ├── locking-selftest-wlock-softirq.h
│   ├── locking-selftest-wsem.h
│   ├── lockref.c
│   ├── logic_iomem.c
│   ├── logic_pio.c
│   ├── lru_cache.c
│   ├── lshrdi3.c
│   ├── lz4
│   ├── lzo
│   ├── Makefile
│   ├── math
│   ├── memcat_p.c
│   ├── memneq.c
│   ├── memory-notifier-error-inject.c
│   ├── memregion.c
│   ├── memweight.c
│   ├── mpi
│   ├── muldi3.c
│   ├── netdev-notifier-error-inject.c
│   ├── net_utils.c
│   ├── nlattr.c
│   ├── nmi_backtrace.c
│   ├── nodemask.c
│   ├── notifier-error-inject.c
│   ├── notifier-error-inject.h
│   ├── objagg.c
│   ├── of-reconfig-notifier-error-inject.c
│   ├── oid_registry.c
│   ├── once.c
│   ├── packing.c
│   ├── parman.c
│   ├── parser.c
│   ├── pci_iomap.c
│   ├── percpu_counter.c
│   ├── percpu-refcount.c
│   ├── percpu_test.c
│   ├── pldmfw
│   ├── plist.c
│   ├── pm-notifier-error-inject.c
│   ├── radix-tree.c
│   ├── raid6
│   ├── random32.c
│   ├── ratelimit.c
│   ├── rbtree.c
│   ├── rbtree_test.c
│   ├── reed_solomon
│   ├── refcount.c
│   ├── rhashtable.c
│   ├── sbitmap.c
│   ├── scatterlist.c
│   ├── seq_buf.c
│   ├── sg_pool.c
│   ├── sg_split.c
│   ├── sha1.c
│   ├── show_mem.c
│   ├── siphash.c
│   ├── slub_kunit.c
│   ├── smp_processor_id.c
│   ├── sort.c
│   ├── stackdepot.c
│   ├── stmp_device.c
│   ├── string.c
│   ├── string_helpers.c
│   ├── strncpy_from_user.c
│   ├── strnlen_user.c
│   ├── syscall.c
│   ├── test_bitmap.c
│   ├── test_bitops.c
│   ├── test_bits.c
│   ├── test_blackhole_dev.c
│   ├── test_bpf.c
│   ├── test_debug_virtual.c
│   ├── test_firmware.c
│   ├── test_fpu.c
│   ├── test_free_pages.c
│   ├── test_hash.c
│   ├── test_hexdump.c
│   ├── test_hmm.c
│   ├── test_hmm_uapi.h
│   ├── test_ida.c
│   ├── test_kasan.c
│   ├── test_kasan_module.c
│   ├── test_kmod.c
│   ├── test-kstrtox.c
│   ├── test_linear_ranges.c
│   ├── test_list_sort.c
│   ├── test_lockup.c
│   ├── test_memcat_p.c
│   ├── test_meminit.c
│   ├── test_min_heap.c
│   ├── test_module.c
│   ├── test_objagg.c
│   ├── test_overflow.c
│   ├── test_parman.c
│   ├── test_printf.c
│   ├── test_rhashtable.c
│   ├── test_scanf.c
│   ├── test_siphash.c
│   ├── test_sort.c
│   ├── test_stackinit.c
│   ├── test_static_key_base.c
│   ├── test_static_keys.c
│   ├── test_string.c
│   ├── test-string_helpers.c
│   ├── test_strscpy.c
│   ├── test_sysctl.c
│   ├── test_ubsan.c
│   ├── test_user_copy.c
│   ├── test_uuid.c
│   ├── test_vmalloc.c
│   ├── test_xarray.c
│   ├── textsearch.c
│   ├── timerqueue.c
│   ├── ts_bm.c
│   ├── ts_fsm.c
│   ├── ts_kmp.c
│   ├── ubsan.c
│   ├── ubsan.h
│   ├── ucmpdi2.c
│   ├── ucs2_string.c
│   ├── usercopy.c
│   ├── uuid.c
│   ├── vdso
│   ├── vsprintf.c
│   ├── win_minmax.c
│   ├── xarray.c
│   ├── xxhash.c
│   ├── xz
│   ├── zlib_deflate
│   ├── zlib_dfltcc
│   ├── zlib_inflate
│   └── zstd
├── LICENSES
│   ├── deprecated
│   ├── dual
│   ├── exceptions
│   └── preferred
├── MAINTAINERS
├── Makefile
├── mm
│   ├── backing-dev.c
│   ├── balloon_compaction.c
│   ├── bootmem_info.c
│   ├── cleancache.c
│   ├── cma.c
│   ├── cma_debug.c
│   ├── cma.h
│   ├── cma_sysfs.c
│   ├── compaction.c
│   ├── damon
│   ├── debug.c
│   ├── debug_page_ref.c
│   ├── debug_vm_pgtable.c
│   ├── dmapool.c
│   ├── early_ioremap.c
│   ├── fadvise.c
│   ├── failslab.c
│   ├── filemap.c
│   ├── frontswap.c
│   ├── gup.c
│   ├── gup_test.c
│   ├── gup_test.h
│   ├── highmem.c
│   ├── hmm.c
│   ├── huge_memory.c
│   ├── hugetlb.c
│   ├── hugetlb_cgroup.c
│   ├── hugetlb_vmemmap.c
│   ├── hugetlb_vmemmap.h
│   ├── hwpoison-inject.c
│   ├── init-mm.c
│   ├── internal.h
│   ├── interval_tree.c
│   ├── io-mapping.c
│   ├── ioremap.c
│   ├── kasan
│   ├── Kconfig
│   ├── Kconfig.debug
│   ├── kfence
│   ├── khugepaged.c
│   ├── kmemleak.c
│   ├── ksm.c
│   ├── list_lru.c
│   ├── maccess.c
│   ├── madvise.c
│   ├── Makefile
│   ├── mapping_dirty_helpers.c
│   ├── memblock.c
│   ├── memcontrol.c
│   ├── memfd.c
│   ├── memory.c
│   ├── memory-failure.c
│   ├── memory_hotplug.c
│   ├── mempolicy.c
│   ├── mempool.c
│   ├── memremap.c
│   ├── memtest.c
│   ├── migrate.c
│   ├── mincore.c
│   ├── mlock.c
│   ├── mmap.c
│   ├── mmap_lock.c
│   ├── mm_init.c
│   ├── mmu_gather.c
│   ├── mmu_notifier.c
│   ├── mmzone.c
│   ├── mprotect.c
│   ├── mremap.c
│   ├── msync.c
│   ├── nommu.c
│   ├── oom_kill.c
│   ├── page_alloc.c
│   ├── page_counter.c
│   ├── page_ext.c
│   ├── page_idle.c
│   ├── page_io.c
│   ├── page_isolation.c
│   ├── page_owner.c
│   ├── page_poison.c
│   ├── page_reporting.c
│   ├── page_reporting.h
│   ├── page_vma_mapped.c
│   ├── pagewalk.c
│   ├── page-writeback.c
│   ├── percpu.c
│   ├── percpu-internal.h
│   ├── percpu-km.c
│   ├── percpu-stats.c
│   ├── percpu-vm.c
│   ├── pgalloc-track.h
│   ├── pgtable-generic.c
│   ├── process_vm_access.c
│   ├── ptdump.c
│   ├── readahead.c
│   ├── rmap.c
│   ├── rodata_test.c
│   ├── secretmem.c
│   ├── shmem.c
│   ├── shuffle.c
│   ├── shuffle.h
│   ├── slab.c
│   ├── slab_common.c
│   ├── slab.h
│   ├── slob.c
│   ├── slub.c
│   ├── sparse.c
│   ├── sparse-vmemmap.c
│   ├── swap.c
│   ├── swap_cgroup.c
│   ├── swapfile.c
│   ├── swap_slots.c
│   ├── swap_state.c
│   ├── truncate.c
│   ├── usercopy.c
│   ├── userfaultfd.c
│   ├── util.c
│   ├── vmacache.c
│   ├── vmalloc.c
│   ├── vmpressure.c
│   ├── vmscan.c
│   ├── vmstat.c
│   ├── workingset.c
│   ├── z3fold.c
│   ├── zbud.c
│   ├── zpool.c
│   ├── zsmalloc.c
│   └── zswap.c
├── net
│   ├── 6lowpan
│   ├── 802
│   ├── 8021q
│   ├── 9p
│   ├── appletalk
│   ├── atm
│   ├── ax25
│   ├── batman-adv
│   ├── bluetooth
│   ├── bpf
│   ├── bpfilter
│   ├── bridge
│   ├── caif
│   ├── can
│   ├── ceph
│   ├── compat.c
│   ├── core
│   ├── dcb
│   ├── dccp
│   ├── decnet
│   ├── devres.c
│   ├── dns_resolver
│   ├── dsa
│   ├── ethernet
│   ├── ethtool
│   ├── hsr
│   ├── ieee802154
│   ├── ife
│   ├── ipv4
│   ├── ipv6
│   ├── iucv
│   ├── kcm
│   ├── Kconfig
│   ├── key
│   ├── l2tp
│   ├── l3mdev
│   ├── lapb
│   ├── llc
│   ├── mac80211
│   ├── mac802154
│   ├── Makefile
│   ├── mctp
│   ├── mpls
│   ├── mptcp
│   ├── ncsi
│   ├── netfilter
│   ├── netlabel
│   ├── netlink
│   ├── netrom
│   ├── nfc
│   ├── nsh
│   ├── openvswitch
│   ├── packet
│   ├── phonet
│   ├── psample
│   ├── qrtr
│   ├── rds
│   ├── rfkill
│   ├── rose
│   ├── rxrpc
│   ├── sched
│   ├── sctp
│   ├── smc
│   ├── socket.c
│   ├── strparser
│   ├── sunrpc
│   ├── switchdev
│   ├── sysctl_net.c
│   ├── tipc
│   ├── tls
│   ├── unix
│   ├── vmw_vsock
│   ├── wireless
│   ├── x25
│   ├── xdp
│   └── xfrm
├── oe-local-files
│   ├── android-drivers.cfg
│   ├── audit.cfg
│   ├── btusb.cfg
│   ├── can-bus.cfg
│   ├── can-devices.cfg
│   ├── default-cpu-governor.cfg
│   ├── disable_most.cfg
│   ├── fanotify.cfg
│   ├── hid.cfg
│   ├── i2c-led.cfg
│   ├── iiodevice.cfg
│   ├── joystick.cfg
│   ├── nfc.cfg
│   ├── overlayfs.cfg
│   ├── powersave.cfg
│   ├── raspberrypi-hciuart.cfg
│   ├── raspberrypi_network.cfg
│   ├── raspberrypi-panel.cfg
│   ├── rtc.cfg
│   ├── rtl_sdr.cfg
│   ├── selinux.cfg
│   ├── sound.cfg
│   ├── systemd-required.cfg
│   ├── systemd-sandbox.cfg
│   ├── systemtap.cfg
│   ├── usbaudio.cfg
│   ├── usb.cfg
│   ├── usbmodem.cfg
│   ├── uvc.cfg
│   ├── vc4graphics.cfg
│   └── wifi.cfg
├── README
├── README.md
├── samples
│   ├── acrn
│   ├── auxdisplay
│   ├── binderfs
│   ├── bpf
│   ├── configfs
│   ├── connector
│   ├── ftrace
│   ├── hidraw
│   ├── hw_breakpoint
│   ├── Kconfig
│   ├── kdb
│   ├── kfifo
│   ├── kmemleak
│   ├── kobject
│   ├── kprobes
│   ├── landlock
│   ├── livepatch
│   ├── Makefile
│   ├── mei
│   ├── nitro_enclaves
│   ├── pidfd
│   ├── pktgen
│   ├── qmi
│   ├── rpmsg
│   ├── seccomp
│   ├── timers
│   ├── trace_events
│   ├── trace_printk
│   ├── uhid
│   ├── v4l
│   ├── vfio-mdev
│   ├── vfs
│   ├── watchdog
│   └── watch_queue
├── scripts
│   ├── adjust_autoksyms.sh
│   ├── asn1_compiler.c
│   ├── as-version.sh
│   ├── atomic
│   ├── basic
│   ├── bin2c.c
│   ├── bloat-o-meter
│   ├── bootgraph.pl
│   ├── bpf_doc.py
│   ├── cc-can-link.sh
│   ├── cc-version.sh
│   ├── checkdeclares.pl
│   ├── check_extable.sh
│   ├── checkincludes.pl
│   ├── checkkconfigsymbols.py
│   ├── checkpatch.pl
│   ├── checkstack.pl
│   ├── checksyscalls.sh
│   ├── check-sysctl-docs
│   ├── checkversion.pl
│   ├── clang-tools
│   ├── cleanfile
│   ├── cleanpatch
│   ├── coccicheck
│   ├── coccinelle
│   ├── config
│   ├── const_structs.checkpatch
│   ├── decodecode
│   ├── decode_stacktrace.sh
│   ├── depmod.sh
│   ├── dev-needs.sh
│   ├── diffconfig
│   ├── documentation-file-ref-check
│   ├── dtc
│   ├── dummy-tools
│   ├── export_report.pl
│   ├── extract-cert.c
│   ├── extract-ikconfig
│   ├── extract-module-sig.pl
│   ├── extract-sys-certs.pl
│   ├── extract-vmlinux
│   ├── extract_xc3028.pl
│   ├── faddr2line
│   ├── file-size.sh
│   ├── find-unused-docs.sh
│   ├── gcc-goto.sh
│   ├── gcc-ld
│   ├── gcc-plugins
│   ├── gcc-x86_32-has-stack-protector.sh
│   ├── gcc-x86_64-has-stack-protector.sh
│   ├── gdb
│   ├── gen_autoksyms.sh
│   ├── generate_initcall_order.pl
│   ├── gen_ksymdeps.sh
│   ├── genksyms
│   ├── get_abi.pl
│   ├── get_dvb_firmware
│   ├── get_feat.pl
│   ├── get_maintainer.pl
│   ├── gfp-translate
│   ├── headerdep.pl
│   ├── headers_check.pl
│   ├── headers_install.sh
│   ├── insert-sys-cert.c
│   ├── jobserver-exec
│   ├── kallsyms.c
│   ├── Kbuild.include
│   ├── kconfig
│   ├── Kconfig.include
│   ├── kernel-doc
│   ├── ksymoops
│   ├── ld-version.sh
│   ├── leaking_addresses.pl
│   ├── Lindent
│   ├── link-vmlinux.sh
│   ├── Makefile
│   ├── Makefile.asm-generic
│   ├── Makefile.build
│   ├── Makefile.clang
│   ├── Makefile.clean
│   ├── Makefile.compiler
│   ├── Makefile.dtbinst
│   ├── Makefile.extrawarn
│   ├── Makefile.gcc-plugins
│   ├── Makefile.headersinst
│   ├── Makefile.host
│   ├── Makefile.kasan
│   ├── Makefile.kcov
│   ├── Makefile.kcsan
│   ├── Makefile.lib
│   ├── Makefile.modfinal
│   ├── Makefile.modinst
│   ├── Makefile.modpost
│   ├── Makefile.package
│   ├── Makefile.ubsan
│   ├── Makefile.userprogs
│   ├── makelst
│   ├── markup_oops.pl
│   ├── min-tool-version.sh
│   ├── mkcompile_h
│   ├── mksysmap
│   ├── mkuboot.sh
│   ├── mod
│   ├── module.lds.S
│   ├── modules-check.sh
│   ├── nsdeps
│   ├── objdiff
│   ├── package
│   ├── pahole-flags.sh
│   ├── parse-maintainers.pl
│   ├── patch-kernel
│   ├── profile2linkerlist.pl
│   ├── prune-kernel
│   ├── recordmcount.c
│   ├── recordmcount.h
│   ├── recordmcount.pl
│   ├── remove-stale-files
│   ├── selinux
│   ├── setlocalversion
│   ├── show_delta
│   ├── sign-file.c
│   ├── sorttable.c
│   ├── sorttable.h
│   ├── spdxcheck.py
│   ├── spdxcheck-test.sh
│   ├── spelling.txt
│   ├── sphinx-pre-install
│   ├── split-man.pl
│   ├── stackdelta
│   ├── stackusage
│   ├── subarch.include
│   ├── syscallhdr.sh
│   ├── syscallnr.sh
│   ├── syscalltbl.sh
│   ├── tags.sh
│   ├── tools-support-relr.sh
│   ├── tracing
│   ├── unifdef.c
│   ├── ver_linux
│   ├── xen-hypercalls.sh
│   └── xz_wrap.sh
├── security
│   ├── apparmor
│   ├── bpf
│   ├── commoncap.c
│   ├── device_cgroup.c
│   ├── inode.c
│   ├── integrity
│   ├── Kconfig
│   ├── Kconfig.hardening
│   ├── keys
│   ├── landlock
│   ├── loadpin
│   ├── lockdown
│   ├── lsm_audit.c
│   ├── Makefile
│   ├── min_addr.c
│   ├── safesetid
│   ├── security.c
│   ├── selinux
│   ├── smack
│   ├── tomoyo
│   └── yama
├── sound
│   ├── ac97
│   ├── ac97_bus.c
│   ├── aoa
│   ├── arm
│   ├── atmel
│   ├── core
│   ├── drivers
│   ├── firewire
│   ├── hda
│   ├── i2c
│   ├── isa
│   ├── Kconfig
│   ├── last.c
│   ├── Makefile
│   ├── mips
│   ├── oss
│   ├── parisc
│   ├── pci
│   ├── pcmcia
│   ├── ppc
│   ├── sh
│   ├── soc
│   ├── sound_core.c
│   ├── sparc
│   ├── spi
│   ├── synth
│   ├── usb
│   ├── virtio
│   ├── x86
│   └── xen
├── tools
│   ├── accounting
│   ├── arch
│   ├── bootconfig
│   ├── bpf
│   ├── build
│   ├── cgroup
│   ├── debugging
│   ├── edid
│   ├── firewire
│   ├── firmware
│   ├── gpio
│   ├── hv
│   ├── iio
│   ├── include
│   ├── io_uring
│   ├── kvm
│   ├── laptop
│   ├── leds
│   ├── lib
│   ├── Makefile
│   ├── memory-model
│   ├── objtool
│   ├── pci
│   ├── pcmcia
│   ├── perf
│   ├── power
│   ├── rcu
│   ├── scripts
│   ├── spi
│   ├── testing
│   ├── thermal
│   ├── time
│   ├── tracing
│   ├── usb
│   ├── virtio
│   ├── vm
│   └── wmi
├── usr
│   ├── default_cpio_list
│   ├── gen_init_cpio.c
│   ├── gen_initramfs.sh
│   ├── include
│   ├── initramfs_data.S
│   ├── Kconfig
│   └── Makefile
└── virt
    ├── kvm
    ├── lib
    └── Makefile

612 directories, 1031 files
```

---

# Cây thư mục trong folder workspace/sources/linux-raspberrypi/arch/arm/boot/dts (chứa device tree):
```
/media/admin1/SSD-480GB/AGL2204/AGL/quillback/raspberrypi4/workspace/sources/linux-raspberrypi/arch/arm/boot/dts$ tree -L 1
.
├── aks-cdu.dts
├── alphascale-asm9260-devkit.dts
├── alphascale-asm9260.dtsi
├── alpine-db.dts
├── alpine.dtsi
├── am335x-baltos.dtsi
├── am335x-baltos-ir2110.dts
├── am335x-baltos-ir3220.dts
├── am335x-baltos-ir5221.dts
├── am335x-baltos-leds.dtsi
├── am335x-base0033.dts
├── am335x-boneblack-common.dtsi
├── am335x-boneblack.dts
├── am335x-boneblack-hdmi.dtsi
├── am335x-boneblack-wireless.dts
├── am335x-boneblue.dts
├── am335x-bone-common.dtsi
├── am335x-bone.dts
├── am335x-bonegreen-common.dtsi
├── am335x-bonegreen.dts
├── am335x-bonegreen-wireless.dts
├── am335x-chiliboard.dts
├── am335x-chilisom.dtsi
├── am335x-cm-t335.dts
├── am335x-evm.dts
```

---
# Nội dung note bên trong một file device tree, ở đây lấy ví dụ là file bcm2711-rpi-4-b.dts (file device tree source của raspberry pi 4 B):
```
// SPDX-License-Identifier: GPL-2.0
/dts-v1/;
#include "bcm2711.dtsi"
#include "bcm2711-rpi.dtsi"
//#include "bcm283x-rpi-usb-peripheral.dtsi"

/ {
	compatible = "raspberrypi,4-model-b", "brcm,bcm2711";
	model = "Raspberry Pi 4 Model B";

	chosen {
		/* 8250 auxiliary UART instead of pl011 */
		stdout-path = "serial1:115200n8";
	};

	leds {
		led-act {
			gpios = <&gpio 42 GPIO_ACTIVE_HIGH>;
		};

		led-pwr {
			label = "PWR";
			gpios = <&expgpio 2 GPIO_ACTIVE_LOW>;
			default-state = "keep";
			linux,default-trigger = "default-on";
		};
	};

	wifi_pwrseq: wifi-pwrseq {
		compatible = "mmc-pwrseq-simple";
		reset-gpios = <&expgpio 1 GPIO_ACTIVE_LOW>;
	};

	sd_io_1v8_reg: sd_io_1v8_reg {
		compatible = "regulator-gpio";
		regulator-name = "vdd-sd-io";
		regulator-min-microvolt = <1800000>;
		regulator-max-microvolt = <3300000>;
		regulator-boot-on;
		regulator-always-on;
		regulator-settling-time-us = <5000>;
		gpios = <&expgpio 4 GPIO_ACTIVE_HIGH>;
		states = <1800000 0x1>,
			 <3300000 0x0>;
		status = "okay";
	};

	sd_vcc_reg: sd_vcc_reg {
		compatible = "regulator-fixed";
		regulator-name = "vcc-sd";
		regulator-min-microvolt = <3300000>;
		regulator-max-microvolt = <3300000>;
		regulator-boot-on;
		enable-active-high;
		gpio = <&expgpio 6 GPIO_ACTIVE_HIGH>;
	};
};

&ddc0 {
	status = "okay";
};

&ddc1 {
	status = "okay";
};

&expgpio {
	gpio-line-names = "BT_ON",
			  "WL_ON",
			  "PWR_LED_OFF",
			  "GLOBAL_RESET",
			  "VDD_SD_IO_SEL",
			  "CAM_GPIO",
			  "SD_PWR_ON",
			  "SD_OC_N";
};

&gpio {
	/*
	 * Parts taken from rpi_SCH_4b_4p0_reduced.pdf and
	 * the official GPU firmware DT blob.
	 *
	 * Legend:
	 * "FOO" = GPIO line named "FOO" on the schematic
	 * "FOO_N" = GPIO line named "FOO" on schematic, active low
	 */
	gpio-line-names = "ID_SDA",
			  "ID_SCL",
			  "SDA1",
			  "SCL1",
			  "GPIO_GCLK",
			  "GPIO5",
			  "GPIO6",
			  "SPI_CE1_N",
			  "SPI_CE0_N",
			  "SPI_MISO",
			  "SPI_MOSI",
			  "SPI_SCLK",
			  "GPIO12",
			  "GPIO13",
			  /* Serial port */
			  "TXD1",
			  "RXD1",
			  "GPIO16",
			  "GPIO17",
			  "GPIO18",
			  "GPIO19",
			  "GPIO20",
			  "GPIO21",
			  "GPIO22",
			  "GPIO23",
			  "GPIO24",
			  "GPIO25",
			  "GPIO26",
			  "GPIO27",
			  "RGMII_MDIO",
			  "RGMIO_MDC",
			  /* Used by BT module */
			  "CTS0",
			  "RTS0",
			  "TXD0",
			  "RXD0",
			  /* Used by Wifi */
			  "SD1_CLK",
			  "SD1_CMD",
			  "SD1_DATA0",
			  "SD1_DATA1",
			  "SD1_DATA2",
			  "SD1_DATA3",
			  /* Shared with SPI flash */
			  "PWM0_MISO",
			  "PWM1_MOSI",
			  "STATUS_LED_G_CLK",
			  "SPIFLASH_CE_N",
			  "SDA0",
			  "SCL0",
			  "RGMII_RXCLK",
			  "RGMII_RXCTL",
			  "RGMII_RXD0",
			  "RGMII_RXD1",
			  "RGMII_RXD2",
			  "RGMII_RXD3",
			  "RGMII_TXCLK",
			  "RGMII_TXCTL",
			  "RGMII_TXD0",
			  "RGMII_TXD1",
			  "RGMII_TXD2",
			  "RGMII_TXD3";
};

&hdmi0 {
	status = "okay";
};

&hdmi1 {
	status = "okay";
};

&pixelvalve0 {
	status = "okay";
};

&pixelvalve1 {
	status = "okay";
};

&pixelvalve2 {
	status = "okay";
};

&pixelvalve4 {
	status = "okay";
};

&pwm1 {
	pinctrl-names = "default";
	pinctrl-0 = <&pwm1_0_gpio40 &pwm1_1_gpio41>;
	status = "okay";
};

/* SDHCI is used to control the SDIO for wireless */
&sdhci {
	#address-cells = <1>;
	#size-cells = <0>;
	pinctrl-names = "default";
	pinctrl-0 = <&emmc_gpio34>;
	bus-width = <4>;
	non-removable;
	mmc-pwrseq = <&wifi_pwrseq>;
	status = "okay";

	brcmf: wifi@1 {
		reg = <1>;
		compatible = "brcm,bcm4329-fmac";
	};
};

/* EMMC2 is used to drive the SD card */
&emmc2 {
	vqmmc-supply = <&sd_io_1v8_reg>;
	vmmc-supply = <&sd_vcc_reg>;
	broken-cd;
	status = "okay";
};

&genet {
	phy-handle = <&phy1>;
	phy-mode = "rgmii-rxid";
	status = "okay";
};

&genet_mdio {
	phy1: ethernet-phy@1 {
		/* No PHY interrupt */
		reg = <0x1>;
	};
};

&pcie0 {
	pci@0,0 {
		device_type = "pci";
		#address-cells = <3>;
		#size-cells = <2>;
		ranges;

		reg = <0 0 0 0 0>;

		usb@0,0 {
			reg = <0 0 0 0 0>;
			resets = <&reset RASPBERRYPI_FIRMWARE_RESET_ID_USB>;
		};
	};
};

/* uart0 communicates with the BT module */
&uart0 {
	pinctrl-names = "default";
	pinctrl-0 = <&uart0_ctsrts_gpio30 &uart0_gpio32>;
	uart-has-rtscts;
	status = "okay";

	bluetooth {
		compatible = "brcm,bcm43438-bt";
		max-speed = <2000000>;
		shutdown-gpios = <&expgpio 0 GPIO_ACTIVE_HIGH>;
	};
};

/* uart1 is mapped to the pin header */
&uart1 {
	pinctrl-names = "default";
	pinctrl-0 = <&uart1_gpio14>;
	status = "okay";
};

&vc4 {
	status = "okay";
};

&vec {
	status = "disabled";
};

// =============================================
// Downstream rpi- changes

#define BCM2711

#include "bcm270x.dtsi"
#include "bcm271x-rpi-bt.dtsi"

/ {
	soc {
		/delete-node/ pixelvalve@7e807000;
		/delete-node/ hdmi@7e902000;
	};
};

#include "bcm2711-rpi-ds.dtsi"
#include "bcm283x-rpi-csi1-2lane.dtsi"
#include "bcm283x-rpi-i2c0mux_0_44.dtsi"

/ {
	chosen {
		bootargs = "coherent_pool=1M 8250.nr_uarts=1 snd_bcm2835.enable_compat_alsa=0 snd_bcm2835.enable_hdmi=1";
	};

	aliases {
		serial0 = &uart1;
		serial1 = &uart0;
		mmc0 = &emmc2;
		mmc1 = &mmcnr;
		mmc2 = &sdhost;
		i2c3 = &i2c3;
		i2c4 = &i2c4;
		i2c5 = &i2c5;
		i2c6 = &i2c6;
		i2c20 = &ddc0;
		i2c21 = &ddc1;
		spi3 = &spi3;
		spi4 = &spi4;
		spi5 = &spi5;
		spi6 = &spi6;
		/delete-property/ intc;
	};

	/delete-node/ wifi-pwrseq;
};

&mmcnr {
	pinctrl-names = "default";
	pinctrl-0 = <&sdio_pins>;
	bus-width = <4>;
	status = "okay";
};

&uart0 {
	pinctrl-0 = <&uart0_pins &bt_pins>;
	status = "okay";
};

&uart1 {
	pinctrl-0 = <&uart1_pins>;
};

```

---

# Cây thư mục của thư mục drivers:
```
/media/admin1/SSD-480GB/AGL2204/AGL/quillback/raspberrypi4/workspace/sources/linux-raspberrypi/drivers$ ls
accessibility  auxdisplay  cdrom        counter  dca      eisa      gnss     hv          idle          ipack      mailbox   memstick  mtd    nvdimm  parport  platform  ptp         reset  sh         spmi     thermal      vfio      vlynq
acpi           base        char         cpufreq  devfreq  extcon    gpio     hwmon       iio           irqchip    Makefile  message   mux    nvme    pci      pnp       pwm         rpmsg  siox       ssb      thunderbolt  vhost     vme
amba           bcma        clk          cpuidle  dio      firewire  gpu      hwspinlock  infiniband    isdn       mcb       mfd       net    nvmem   pcmcia   power     rapidio     rtc    slimbus    staging  tty          video     w1
android        block       clocksource  crypto   dma      firmware  greybus  hwtracing   input         Kconfig    md        misc      nfc    of      perf     powercap  ras         s390   soc        target   uio          virt      watchdog
ata            bluetooth   comedi       cxl      dma-buf  fpga      hid      i2c         interconnect  leds       media     mmc       ntb    opp     phy      pps       regulator   sbus   soundwire  tc       usb          virtio    xen
atm            bus         connector    dax      edac     fsi       hsi      i3c         iommu         macintosh  memory    most      nubus  parisc  pinctrl  ps3       remoteproc  scsi   spi        tee      vdpa         visorbus  zorro

```
+ trích một cấu trúc của một drivers, ở đây giả sử là driver của I2C:
```
/media/admin1/SSD-480GB/AGL2204/AGL/quillback/raspberrypi4/workspace/sources/linux-raspberrypi/drivers/i2c$ tree -L 1
.
├── algos
├── busses
├── i2c-boardinfo.c
├── i2c-core-acpi.c
├── i2c-core-base.c
├── i2c-core.h
├── i2c-core-of.c
├── i2c-core-slave.c
├── i2c-core-smbus.c
├── i2c-dev.c
├── i2c-mux.c
├── i2c-slave-eeprom.c
├── i2c-slave-testunit.c
├── i2c-smbus.c
├── i2c-stub.c
├── Kconfig
├── Makefile
└── muxes

```

+ Nội dung trong file Makefile của drivers:
```
# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the i2c core.
#

obj-$(CONFIG_I2C_BOARDINFO)	+= i2c-boardinfo.o
obj-$(CONFIG_I2C)		+= i2c-core.o
i2c-core-objs 			:= i2c-core-base.o i2c-core-smbus.o
i2c-core-$(CONFIG_ACPI)		+= i2c-core-acpi.o
i2c-core-$(CONFIG_I2C_SLAVE) 	+= i2c-core-slave.o
i2c-core-$(CONFIG_OF) 		+= i2c-core-of.o

obj-$(CONFIG_I2C_SMBUS)		+= i2c-smbus.o
obj-$(CONFIG_I2C_CHARDEV)	+= i2c-dev.o
obj-$(CONFIG_I2C_MUX)		+= i2c-mux.o
obj-y				+= algos/ busses/ muxes/
obj-$(CONFIG_I2C_STUB)		+= i2c-stub.o
obj-$(CONFIG_I2C_SLAVE_EEPROM)	+= i2c-slave-eeprom.o
obj-$(CONFIG_I2C_SLAVE_TESTUNIT)	+= i2c-slave-testunit.o

ccflags-$(CONFIG_I2C_DEBUG_CORE) := -DDEBUG
```
  + Với phần obj-$(CONFIG_I2C_SMBUS) là phần cấu hình tương tự obj-m hoặc obj-y (tùy cấu hình theo như biến config) để sỉnh ra file object như mong muốn

---
# Nội dung trong một file Makefile tổng của driver:
```
# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the Linux kernel device drivers.
#
# 15 Sep 2000, Christoph Hellwig <hch@infradead.org>
# Rewritten to use lists instead of if-statements.
#

obj-y				+= irqchip/
obj-y				+= bus/

obj-$(CONFIG_GENERIC_PHY)	+= phy/

# GPIO must come after pinctrl as gpios may need to mux pins etc
obj-$(CONFIG_PINCTRL)		+= pinctrl/
obj-$(CONFIG_GPIOLIB)		+= gpio/
obj-y				+= pwm/

obj-y				+= pci/

obj-$(CONFIG_PARISC)		+= parisc/
obj-$(CONFIG_RAPIDIO)		+= rapidio/
obj-y				+= video/
obj-y				+= idle/

# IPMI must come before ACPI in order to provide IPMI opregion support
obj-y				+= char/ipmi/

obj-$(CONFIG_ACPI)		+= acpi/

# PnP must come after ACPI since it will eventually need to check if acpi
# was used and do nothing if so
obj-$(CONFIG_PNP)		+= pnp/
obj-y				+= amba/

obj-y				+= clk/
# Many drivers will want to use DMA so this has to be made available
# really early.
obj-$(CONFIG_DMADEVICES)	+= dma/

# SOC specific infrastructure drivers.
obj-y				+= soc/

obj-y				+= virtio/
obj-$(CONFIG_VDPA)		+= vdpa/
obj-$(CONFIG_XEN)		+= xen/

# regulators early, since some subsystems rely on them to initialize
obj-$(CONFIG_REGULATOR)		+= regulator/

# reset controllers early, since gpu drivers might rely on them to initialize
obj-$(CONFIG_RESET_CONTROLLER)	+= reset/

# tty/ comes before char/ so that the VT console is the boot-time
# default.
obj-y				+= tty/
obj-y				+= char/

# iommu/ comes before gpu as gpu are using iommu controllers
obj-y				+= iommu/

# gpu/ comes after char for AGP vs DRM startup and after iommu
obj-y				+= gpu/

obj-$(CONFIG_CONNECTOR)		+= connector/

# i810fb and intelfb depend on char/agp/
obj-$(CONFIG_FB_I810)           += video/fbdev/i810/
obj-$(CONFIG_FB_INTEL)          += video/fbdev/intelfb/

obj-$(CONFIG_PARPORT)		+= parport/
obj-y				+= base/ block/ misc/ mfd/ nfc/
obj-$(CONFIG_LIBNVDIMM)		+= nvdimm/
obj-$(CONFIG_DAX)		+= dax/
obj-$(CONFIG_CXL_BUS)		+= cxl/
obj-$(CONFIG_DMA_SHARED_BUFFER) += dma-buf/
obj-$(CONFIG_NUBUS)		+= nubus/
obj-y				+= macintosh/
obj-y				+= scsi/
obj-y				+= nvme/
obj-$(CONFIG_ATA)		+= ata/
obj-$(CONFIG_TARGET_CORE)	+= target/
obj-$(CONFIG_MTD)		+= mtd/
obj-$(CONFIG_SPI)		+= spi/
obj-$(CONFIG_SPMI)		+= spmi/
obj-$(CONFIG_HSI)		+= hsi/
obj-$(CONFIG_SLIMBUS)		+= slimbus/
obj-y				+= net/
obj-$(CONFIG_ATM)		+= atm/
obj-$(CONFIG_FUSION)		+= message/
obj-y				+= firewire/
obj-$(CONFIG_UIO)		+= uio/
obj-$(CONFIG_VFIO)		+= vfio/
obj-y				+= cdrom/
obj-y				+= auxdisplay/
obj-$(CONFIG_PCCARD)		+= pcmcia/
obj-$(CONFIG_DIO)		+= dio/
obj-$(CONFIG_SBUS)		+= sbus/
obj-$(CONFIG_ZORRO)		+= zorro/
obj-$(CONFIG_ATA_OVER_ETH)	+= block/aoe/
obj-$(CONFIG_PARIDE) 		+= block/paride/
obj-$(CONFIG_TC)		+= tc/
obj-$(CONFIG_USB_PHY)		+= usb/
obj-$(CONFIG_USB)		+= usb/
obj-$(CONFIG_USB_SUPPORT)	+= usb/
obj-$(CONFIG_PCI)		+= usb/
obj-$(CONFIG_USB_GADGET)	+= usb/
obj-$(CONFIG_OF)		+= usb/
obj-$(CONFIG_SERIO)		+= input/serio/
obj-$(CONFIG_GAMEPORT)		+= input/gameport/
obj-$(CONFIG_INPUT)		+= input/
obj-$(CONFIG_RTC_LIB)		+= rtc/
obj-y				+= i2c/ i3c/ media/
obj-$(CONFIG_PPS)		+= pps/
obj-y				+= ptp/
obj-$(CONFIG_W1)		+= w1/
obj-y				+= power/
obj-$(CONFIG_HWMON)		+= hwmon/
obj-$(CONFIG_THERMAL)		+= thermal/
obj-$(CONFIG_WATCHDOG)		+= watchdog/
obj-$(CONFIG_MD)		+= md/
obj-$(CONFIG_BT)		+= bluetooth/
obj-$(CONFIG_ACCESSIBILITY)	+= accessibility/
obj-$(CONFIG_ISDN)		+= isdn/
obj-$(CONFIG_EDAC)		+= edac/
obj-$(CONFIG_EISA)		+= eisa/
obj-$(CONFIG_PM_OPP)		+= opp/
obj-$(CONFIG_CPU_FREQ)		+= cpufreq/
obj-$(CONFIG_CPU_IDLE)		+= cpuidle/
obj-y				+= mmc/
obj-$(CONFIG_MEMSTICK)		+= memstick/
obj-$(CONFIG_NEW_LEDS)		+= leds/
obj-$(CONFIG_INFINIBAND)	+= infiniband/
obj-y				+= firmware/
obj-$(CONFIG_CRYPTO)		+= crypto/
obj-$(CONFIG_SUPERH)		+= sh/
obj-y				+= clocksource/
obj-$(CONFIG_DCA)		+= dca/
obj-$(CONFIG_HID)		+= hid/
obj-$(CONFIG_PPC_PS3)		+= ps3/
obj-$(CONFIG_OF)		+= of/
obj-$(CONFIG_SSB)		+= ssb/
obj-$(CONFIG_BCMA)		+= bcma/
obj-$(CONFIG_VHOST_RING)	+= vhost/
obj-$(CONFIG_VHOST_IOTLB)	+= vhost/
obj-$(CONFIG_VHOST)		+= vhost/
obj-$(CONFIG_VLYNQ)		+= vlynq/
obj-$(CONFIG_GREYBUS)		+= greybus/
obj-$(CONFIG_COMEDI)		+= comedi/
obj-$(CONFIG_STAGING)		+= staging/
obj-y				+= platform/

obj-$(CONFIG_MAILBOX)		+= mailbox/
obj-$(CONFIG_HWSPINLOCK)	+= hwspinlock/
obj-$(CONFIG_REMOTEPROC)	+= remoteproc/
obj-$(CONFIG_RPMSG)		+= rpmsg/
obj-$(CONFIG_SOUNDWIRE)		+= soundwire/

# Virtualization drivers
obj-$(CONFIG_VIRT_DRIVERS)	+= virt/
obj-$(subst m,y,$(CONFIG_HYPERV))	+= hv/

obj-$(CONFIG_PM_DEVFREQ)	+= devfreq/
obj-$(CONFIG_EXTCON)		+= extcon/
obj-$(CONFIG_MEMORY)		+= memory/
obj-$(CONFIG_IIO)		+= iio/
obj-$(CONFIG_VME_BUS)		+= vme/
obj-$(CONFIG_IPACK_BUS)		+= ipack/
obj-$(CONFIG_NTB)		+= ntb/
obj-$(CONFIG_POWERCAP)		+= powercap/
obj-$(CONFIG_MCB)		+= mcb/
obj-$(CONFIG_PERF_EVENTS)	+= perf/
obj-$(CONFIG_RAS)		+= ras/
obj-$(CONFIG_USB4)		+= thunderbolt/
obj-$(CONFIG_CORESIGHT)		+= hwtracing/coresight/
obj-y				+= hwtracing/intel_th/
obj-$(CONFIG_STM)		+= hwtracing/stm/
obj-$(CONFIG_ANDROID)		+= android/
obj-$(CONFIG_NVMEM)		+= nvmem/
obj-$(CONFIG_FPGA)		+= fpga/
obj-$(CONFIG_FSI)		+= fsi/
obj-$(CONFIG_TEE)		+= tee/
obj-$(CONFIG_MULTIPLEXER)	+= mux/
obj-$(CONFIG_UNISYS_VISORBUS)	+= visorbus/
obj-$(CONFIG_SIOX)		+= siox/
obj-$(CONFIG_GNSS)		+= gnss/
obj-$(CONFIG_INTERCONNECT)	+= interconnect/
obj-$(CONFIG_COUNTER)		+= counter/
obj-$(CONFIG_MOST)		+= most/

```

